test_run = require('test_run').new()

test_run:cmd("push filter 'Invalid VYLOG file: Slice [0-9]+ deleted but not registered'" .. \
             "to 'Invalid VYLOG file: Slice <NUM> deleted but not registered'")

fiber = require 'fiber'
fio = require 'fio'
xlog = require 'xlog'

s = box.schema.space.create('test', {engine='vinyl'})
_ = s:create_index('pk')

-- Start a few fibers populating the space in the background.
n_workers = 3
c = fiber.channel(n_workers)
test_run:cmd("setopt delimiter ';'")
for i=1,n_workers do
    fiber.create(function()
        for j=i,1000,n_workers do
            s:insert{j}
        end
        c:put(true)
    end)
end
test_run:cmd("setopt delimiter ''");

-- Let the background fibers run.
fiber.sleep(0.001)

-- Concurrent checkpoint.
box.snapshot()

-- Join background fibers.
for i=1,n_workers do c:get() end

-- Get list of files from the last checkpoint.
files = box.backup.start()

-- Extract the last checkpoint LSN and find
-- max LSN stored in run files.
snap_lsn = -1
run_lsn = -1
test_run:cmd("setopt delimiter ';'")
for _, path in ipairs(files) do
    suffix = string.gsub(path, '.*%.', '')
    if suffix == 'snap' then
        snap_lsn = tonumber(fio.basename(path, '.snap'))
    end
    if suffix == 'run' then
        for lsn, _ in xlog.pairs(path) do
            if run_lsn < lsn then run_lsn = lsn end
        end
    end
end
test_run:cmd("setopt delimiter ''");
snap_lsn >= 0
run_lsn >= 0

box.backup.stop()

-- Check that run files only contain statements
-- inserted before checkpoint.
snap_lsn == run_lsn or require('log').error("snap_lsn = " .. snap_lsn .. ", run_lsn = " .. run_lsn)

s:drop()

--
-- gh-2614 about broken vy_run_iterator_start_from.
--
s = box.schema.space.create('test', {engine = 'vinyl'})
p = s:create_index('pk')
s:replace{100}
s:replace{101}
s:replace{102}
s:replace{103}
box.snapshot()
s:select({99}, {iterator = box.index.LE, limit = 10})
s:drop()
