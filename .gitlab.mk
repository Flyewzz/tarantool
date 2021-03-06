GITLAB_MAKE:=${MAKE} -f .gitlab.mk
TRAVIS_MAKE:=${MAKE} -f .travis.mk

# Pass *_no_deps goals to .travis.mk.
test_%:
	${TRAVIS_MAKE} $@

# #######################################################
# Build and push testing docker images to GitLab Registry
# #######################################################

# These images contains tarantool dependencies and testing
# dependencies to run tests in them.
#
# How to run:
#
# make GITLAB_USER=foo -f .gitlab.mk docker_bootstrap
#
# The command will prompt for a password. If two-factor
# authentication is enabled an access token with 'api' scope
# should be entered here instead of a password.
#
# When to run:
#
# When some of deps_* goals in .travis.mk are updated.
#
# Keep in a mind that the resulting image is used to run tests on
# all branches, so avoid removing packages: only add them.

GITLAB_REGISTRY?=registry.gitlab.com
DOCKER_BUILD=docker build --network=host -f - .

define DEBIAN_STRETCH_DOCKERFILE
FROM packpack/packpack:debian-stretch
COPY .travis.mk .
RUN make -f .travis.mk deps_debian
endef
export DEBIAN_STRETCH_DOCKERFILE

define DEBIAN_BUSTER_DOCKERFILE
FROM packpack/packpack:debian-buster
COPY .travis.mk .
RUN make APT_EXTRA_FLAGS="--allow-releaseinfo-change-version --allow-releaseinfo-change-suite" -f .travis.mk deps_buster_clang_8 deps_buster_clang_11
endef
export DEBIAN_BUSTER_DOCKERFILE

IMAGE_PREFIX:=${GITLAB_REGISTRY}/tarantool/tarantool/testing
DEBIAN_STRETCH_IMAGE:=${IMAGE_PREFIX}/debian-stretch
DEBIAN_BUSTER_IMAGE:=${IMAGE_PREFIX}/debian-buster

TRAVIS_CI_MD5SUM:=$(firstword $(shell md5sum .travis.mk))

docker_bootstrap:
	# Login.
	docker login -u ${GITLAB_USER} ${GITLAB_REGISTRY}
	# Build images.
	echo "$${DEBIAN_STRETCH_DOCKERFILE}" | ${DOCKER_BUILD} \
		-t ${DEBIAN_STRETCH_IMAGE}:${TRAVIS_CI_MD5SUM} \
		-t ${DEBIAN_STRETCH_IMAGE}:latest
	echo "$${DEBIAN_BUSTER_DOCKERFILE}" | ${DOCKER_BUILD} \
		-t ${DEBIAN_BUSTER_IMAGE}:${TRAVIS_CI_MD5SUM} \
		-t ${DEBIAN_BUSTER_IMAGE}:latest
	# Push images.
	docker push ${DEBIAN_STRETCH_IMAGE}:${TRAVIS_CI_MD5SUM}
	docker push ${DEBIAN_BUSTER_IMAGE}:${TRAVIS_CI_MD5SUM}
	docker push ${DEBIAN_STRETCH_IMAGE}:latest
	docker push ${DEBIAN_BUSTER_IMAGE}:latest

# Clone the benchmarks repository for performance testing
perf_clone_benchs_repo:
	git clone https://github.com/tarantool/bench-run.git

# Build images for performance testing
perf_prepare: perf_clone_benchs_repo
	make -f bench-run/targets.mk prepare

# Remove temporary performance image
perf_cleanup_image:
	make -f bench-run/targets.mk cleanup

# Remove temporary performance image from the test host
perf_cleanup: perf_clone_benchs_repo perf_cleanup_image

# #################################
# Run tests under a virtual machine
# #################################

vms_start:
	VBoxManage controlvm ${VMS_NAME} poweroff || true
	VBoxManage snapshot ${VMS_NAME} restore ${VMS_NAME}
	VBoxManage startvm ${VMS_NAME} --type headless

vms_test_%:
	tar czf - ../tarantool | ssh ${VMS_USER}@127.0.0.1 -p ${VMS_PORT} tar xzf -
	ssh ${VMS_USER}@127.0.0.1 -p ${VMS_PORT} "/bin/bash -c \
		'${EXTRA_ENV} \
		cd tarantool && \
		${TRAVIS_MAKE} $(subst vms_,,$@)'"

vms_shutdown:
	VBoxManage controlvm ${VMS_NAME} poweroff

# ######
# Deploy
# ######

GIT_DESCRIBE=$(shell git describe HEAD)
MAJOR_VERSION=$(word 1,$(subst ., ,$(GIT_DESCRIBE)))
MINOR_VERSION=$(word 2,$(subst ., ,$(GIT_DESCRIBE)))
BUCKET="$(MAJOR_VERSION).$(MINOR_VERSION)"
S3_BUCKET_URL="s3://tarantool_repo/sources/$(BUCKET)"

deploy_prepare:
	[ -d packpack ] || \
		git clone https://github.com/packpack/packpack.git packpack
	rm -rf build

package: deploy_prepare
	PACKPACK_EXTRA_DOCKER_RUN_PARAMS="--network=host ${PACKPACK_EXTRA_DOCKER_RUN_PARAMS}" ./packpack/packpack

deploy: package
	echo ${GPG_SECRET_KEY} | base64 -d | gpg --batch --import || true
	./tools/update_repo.sh -o=${OS} -d=${DIST} \
		-b="${LIVE_REPO_S3_DIR}/${BUCKET}" build
	if [ "${CI_COMMIT_TAG}" != "" ]; then \
		./tools/update_repo.sh -o=${OS} -d=${DIST} \
			-b="${RELEASE_REPO_S3_DIR}/${BUCKET}" build ; \
	fi

source: deploy_prepare
	TARBALL_COMPRESSOR=gz packpack/packpack tarball

source_deploy: source
	( aws --endpoint-url "${AWS_S3_ENDPOINT_URL}" s3 ls "${S3_BUCKET_URL}/" || \
		( rm -rf "${BUCKET}" ; mkdir "${BUCKET}" &&                        \
			aws --endpoint-url "${AWS_S3_ENDPOINT_URL}"                \
				s3 mv "${BUCKET}" "${S3_BUCKET_URL}" --recursive   \
				--acl public-read ) ) &&                           \
		aws --endpoint-url "${AWS_S3_ENDPOINT_URL}"                        \
			s3 cp build/*.tar.gz "${S3_BUCKET_URL}/" --acl public-read

# ###################
# Performance testing
# ###################

perf_run:
	/opt/bench-run/benchs/${BENCH}/run.sh ${ARG}
