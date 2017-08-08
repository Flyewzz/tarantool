#ifndef TARANTOOL_BOX_VINYL_INDEX_H_INCLUDED
#define TARANTOOL_BOX_VINYL_INDEX_H_INCLUDED
/*
 * Copyright 2010-2016, Tarantool AUTHORS, please see AUTHORS file.
 *
 * Redistribution and use in source and binary forms, with or
 * without modification, are permitted provided that the following
 * conditions are met:
 *
 * 1. Redistributions of source code must retain the above
 *    copyright notice, this list of conditions and the
 *    following disclaimer.
 *
 * 2. Redistributions in binary form must reproduce the above
 *    copyright notice, this list of conditions and the following
 *    disclaimer in the documentation and/or other materials
 *    provided with the distribution.
 *
 * THIS SOFTWARE IS PROVIDED BY <COPYRIGHT HOLDER> ``AS IS'' AND
 * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED
 * TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
 * A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL
 * <COPYRIGHT HOLDER> OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT,
 * INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
 * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
 * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR
 * BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF
 * LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF
 * THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF
 * SUCH DAMAGE.
 */
#include "index.h"

struct vy_index;
struct vy_env;

/**
 * C++ wrapper for struct vy_index.
 */
struct VinylIndex: public Index
{
public:
	VinylIndex(struct vy_env *env, struct index_def *index_def,
		   struct tuple_format *format, struct vy_index *pk);
	virtual ~VinylIndex() override;

	/**
	 * Open this vinyl index. Called on index creation
	 * before WAL write. May throw an exception.
	 */
	void open();

	virtual void commitCreate(int64_t signature) override;
	virtual void commitDrop() override;

	virtual struct tuple*
	findByKey(const char *key, uint32_t) const override;

	virtual struct iterator*
	allocIterator() const override;

	virtual void
	initIterator(struct iterator *iterator,
		     enum iterator_type type,
		     const char *key, uint32_t part_count) const override;

	virtual size_t
	bsize() const override;

	virtual struct tuple *
	min(const char *key, uint32_t part_count) const override;

	virtual struct tuple *
	max(const char *key, uint32_t part_count) const override;

	virtual size_t
	count(enum iterator_type type, const char *key, uint32_t part_count)
		const override;

	virtual void
	info(struct info_handler *handler) const override;

	struct vy_env *env;
	struct vy_index *db;
};

#endif /* TARANTOOL_BOX_VINYL_INDEX_H_INCLUDED */
