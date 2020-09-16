/*
 * Keep the symbols sorted by name for search and addition
 * simplicity, to avoid duplicates. Makes no much sense to
 * split them into any sections. Anyway some symbols will
 * end-up belonging to several of them at once, and it
 * would require moving lines here when a symbol goes from
 * privately exported to the public C API.
 */
EXPORT(base64_bufsize)
EXPORT(base64_decode)
EXPORT(base64_encode)
EXPORT(box_delete)
EXPORT(box_error_clear)
EXPORT(box_error_code)
EXPORT(box_error_custom_type)
EXPORT(box_error_last)
EXPORT(box_error_message)
EXPORT(box_error_set)
EXPORT(box_error_type)
EXPORT(box_index_bsize)
EXPORT(box_index_count)
EXPORT(box_index_get)
EXPORT(box_index_id_by_name)
EXPORT(box_index_iterator)
EXPORT(box_index_len)
EXPORT(box_index_max)
EXPORT(box_index_min)
EXPORT(box_index_random)
EXPORT(box_insert)
EXPORT(box_iterator_free)
EXPORT(box_iterator_next)
EXPORT(box_key_def_delete)
EXPORT(box_key_def_dump_parts)
EXPORT(box_key_def_extract_key)
EXPORT(box_key_def_merge)
EXPORT(box_key_def_new)
EXPORT(box_key_def_new_v2)
EXPORT(box_key_def_validate_key)
EXPORT(box_key_def_validate_tuple)
EXPORT(box_key_part_def_create)
EXPORT(box_latch_delete)
EXPORT(box_latch_lock)
EXPORT(box_latch_new)
EXPORT(box_latch_trylock)
EXPORT(box_latch_unlock)
EXPORT(box_region_aligned_alloc)
EXPORT(box_region_alloc)
EXPORT(box_region_truncate)
EXPORT(box_region_used)
EXPORT(box_replace)
EXPORT(box_return_mp)
EXPORT(box_return_tuple)
EXPORT(box_schema_version)
EXPORT(box_select)
EXPORT(box_sequence_current)
EXPORT(box_sequence_next)
EXPORT(box_sequence_reset)
EXPORT(box_sequence_set)
EXPORT(box_session_push)
EXPORT(box_space_id_by_name)
EXPORT(box_truncate)
EXPORT(box_tuple_bsize)
EXPORT(box_tuple_compare)
EXPORT(box_tuple_compare_with_key)
EXPORT(box_tuple_extract_key)
EXPORT(box_tuple_field)
EXPORT(box_tuple_field_count)
EXPORT(box_tuple_format)
EXPORT(box_tuple_format_default)
EXPORT(box_tuple_format_new)
EXPORT(box_tuple_format_ref)
EXPORT(box_tuple_format_unref)
EXPORT(box_tuple_iterator)
EXPORT(box_tuple_iterator_free)
EXPORT(box_tuple_new)
EXPORT(box_tuple_next)
EXPORT(box_tuple_position)
EXPORT(box_tuple_ref)
EXPORT(box_tuple_rewind)
EXPORT(box_tuple_seek)
EXPORT(box_tuple_to_buf)
EXPORT(box_tuple_unref)
EXPORT(box_tuple_update)
EXPORT(box_tuple_upsert)
EXPORT(box_txn)
EXPORT(box_txn_alloc)
EXPORT(box_txn_begin)
EXPORT(box_txn_commit)
EXPORT(box_txn_id)
EXPORT(box_txn_rollback)
EXPORT(box_txn_rollback_to_savepoint)
EXPORT(box_txn_savepoint)
EXPORT(box_update)
EXPORT(box_upsert)
EXPORT(clock_monotonic64)
EXPORT(clock_monotonic)
EXPORT(clock_process64)
EXPORT(clock_process)
EXPORT(clock_realtime64)
EXPORT(clock_realtime)
EXPORT(clock_thread64)
EXPORT(clock_thread)
EXPORT(coio_call)
EXPORT(coio_close)
EXPORT(coio_getaddrinfo)
EXPORT(coio_wait)
EXPORT(console_get_output_format)
EXPORT(console_set_output_format)
EXPORT(cord_slab_cache)
EXPORT(crc32_calc)
EXPORT(crypto_EVP_MD_CTX_free)
EXPORT(crypto_EVP_MD_CTX_new)
EXPORT(crypto_HMAC_CTX_free)
EXPORT(crypto_HMAC_CTX_new)
EXPORT(crypto_stream_append)
EXPORT(crypto_stream_begin)
EXPORT(crypto_stream_commit)
EXPORT(crypto_stream_delete)
EXPORT(crypto_stream_new)
EXPORT(csv_create)
EXPORT(csv_destroy)
EXPORT(csv_escape_field)
EXPORT(csv_feed)
EXPORT(csv_iterator_create)
EXPORT(csv_next)
EXPORT(csv_setopt)
EXPORT(decimal_unpack)
EXPORT(error_ref)
EXPORT(error_set_prev)
EXPORT(error_unpack_unsafe)
EXPORT(error_unref)
EXPORT(exception_get_int)
EXPORT(exception_get_string)
EXPORT(fiber_attr_delete)
EXPORT(fiber_attr_getstacksize)
EXPORT(fiber_attr_new)
EXPORT(fiber_attr_setstacksize)
EXPORT(fiber_cancel)
EXPORT(fiber_clock64)
EXPORT(fiber_clock)
EXPORT(fiber_cond_broadcast)
EXPORT(fiber_cond_delete)
EXPORT(fiber_cond_new)
EXPORT(fiber_cond_signal)
EXPORT(fiber_cond_wait)
EXPORT(fiber_cond_wait_timeout)
EXPORT(fiber_is_cancelled)
EXPORT(fiber_join)
EXPORT(fiber_new)
EXPORT(fiber_new_ex)
EXPORT(fiber_reschedule)
EXPORT(fiber_self)
EXPORT(fiber_set_cancellable)
EXPORT(fiber_set_joinable)
EXPORT(fiber_sleep)
EXPORT(fiber_start)
EXPORT(fiber_time64)
EXPORT(fiber_time)
EXPORT(fiber_wakeup)
EXPORT(fiber_yield)
EXPORT(guava)
EXPORT(ibuf_create)
EXPORT(ibuf_destroy)
EXPORT(ibuf_reinit)
EXPORT(ibuf_reserve_slow)
EXPORT(lbox_socket_local_resolve)
EXPORT(lbox_socket_nonblock)
EXPORT(log_format)
EXPORT(log_level)
EXPORT(log_pid)
EXPORT(log_type)
EXPORT(lua_atpanic)
EXPORT(lua_call)
EXPORT(lua_checkstack)
EXPORT(lua_close)
EXPORT(lua_concat)
EXPORT(lua_cpcall)
EXPORT(lua_createtable)
EXPORT(lua_dump)
EXPORT(lua_equal)
EXPORT(lua_error)
EXPORT(lua_gc)
EXPORT(lua_getallocf)
EXPORT(lua_getfenv)
EXPORT(lua_getfield)
EXPORT(lua_gethook)
EXPORT(lua_gethookcount)
EXPORT(lua_gethookmask)
EXPORT(lua_getinfo)
EXPORT(lua_getlocal)
EXPORT(lua_getmetatable)
EXPORT(lua_getstack)
EXPORT(lua_gettable)
EXPORT(lua_gettop)
EXPORT(lua_getupvalue)
EXPORT(lua_insert)
EXPORT(lua_iscfunction)
EXPORT(lua_isnumber)
EXPORT(lua_isstring)
EXPORT(lua_isuserdata)
EXPORT(lua_lessthan)
EXPORT(lua_load)
EXPORT(lua_loadx)
EXPORT(lua_newstate)
EXPORT(lua_newthread)
EXPORT(lua_newuserdata)
EXPORT(lua_next)
EXPORT(lua_objlen)
EXPORT(lua_pcall)
EXPORT(lua_pushboolean)
EXPORT(lua_pushcclosure)
EXPORT(lua_pushfstring)
EXPORT(lua_pushinteger)
EXPORT(lua_pushlightuserdata)
EXPORT(lua_pushlstring)
EXPORT(lua_pushnil)
EXPORT(lua_pushnumber)
EXPORT(lua_pushstring)
EXPORT(lua_pushthread)
EXPORT(lua_pushvalue)
EXPORT(lua_pushvfstring)
EXPORT(lua_rawequal)
EXPORT(lua_rawget)
EXPORT(lua_rawgeti)
EXPORT(lua_rawset)
EXPORT(lua_rawseti)
EXPORT(lua_remove)
EXPORT(lua_replace)
EXPORT(lua_resume)
EXPORT(lua_setallocf)
EXPORT(lua_setfenv)
EXPORT(lua_setfield)
EXPORT(lua_sethook)
EXPORT(lua_setlocal)
EXPORT(lua_setmetatable)
EXPORT(lua_settable)
EXPORT(lua_settop)
EXPORT(lua_setupvalue)
EXPORT(lua_static_aligned_alloc)
EXPORT(lua_status)
EXPORT(lua_toboolean)
EXPORT(lua_tocfunction)
EXPORT(lua_tointeger)
EXPORT(lua_tolstring)
EXPORT(lua_tonumber)
EXPORT(lua_topointer)
EXPORT(lua_tothread)
EXPORT(lua_touserdata)
EXPORT(lua_type)
EXPORT(lua_typename)
EXPORT(lua_upvalueid)
EXPORT(lua_upvaluejoin)
EXPORT(lua_xmove)
EXPORT(lua_yield)
EXPORT(luaJIT_profile_dumpstack)
EXPORT(luaJIT_profile_start)
EXPORT(luaJIT_profile_stop)
EXPORT(luaJIT_setmode)
EXPORT(luaL_addlstring)
EXPORT(luaL_addstring)
EXPORT(luaL_addvalue)
EXPORT(luaL_argerror)
EXPORT(luaL_buffinit)
EXPORT(luaL_callmeta)
EXPORT(luaL_cdef)
EXPORT(luaL_checkany)
EXPORT(luaL_checkcdata)
EXPORT(luaL_checkint64)
EXPORT(luaL_checkinteger)
EXPORT(luaL_checklstring)
EXPORT(luaL_checknumber)
EXPORT(luaL_checkoption)
EXPORT(luaL_checkstack)
EXPORT(luaL_checktype)
EXPORT(luaL_checkudata)
EXPORT(luaL_checkuint64)
EXPORT(luaL_ctypeid)
EXPORT(luaL_error)
EXPORT(luaL_execresult)
EXPORT(luaL_fileresult)
EXPORT(luaL_findtable)
EXPORT(luaL_getmetafield)
EXPORT(luaL_gsub)
EXPORT(luaL_iscallable)
EXPORT(luaL_iscdata)
EXPORT(luaL_loadbuffer)
EXPORT(luaL_loadbufferx)
EXPORT(luaL_loadfile)
EXPORT(luaL_loadfilex)
EXPORT(luaL_loadstring)
EXPORT(luaL_newmetatable)
EXPORT(luaL_newstate)
EXPORT(luaL_openlib)
EXPORT(luaL_openlibs)
EXPORT(luaL_optinteger)
EXPORT(luaL_optlstring)
EXPORT(luaL_optnumber)
EXPORT(luaL_prepbuffer)
EXPORT(luaL_pushcdata)
EXPORT(luaL_pushint64)
EXPORT(luaL_pushmodule)
EXPORT(luaL_pushresult)
EXPORT(luaL_pushuint64)
EXPORT(luaL_ref)
EXPORT(luaL_register)
EXPORT(luaL_setcdatagc)
EXPORT(luaL_setfuncs)
EXPORT(luaL_setmetatable)
EXPORT(luaL_testudata)
EXPORT(luaL_toint64)
EXPORT(luaL_touint64)
EXPORT(luaL_traceback)
EXPORT(luaL_typerror)
EXPORT(luaL_unref)
EXPORT(luaL_where)
EXPORT(luaopen_base)
EXPORT(luaopen_bit)
EXPORT(luaopen_debug)
EXPORT(luaopen_ffi)
EXPORT(luaopen_io)
EXPORT(luaopen_jit)
EXPORT(luaopen_math)
EXPORT(luaopen_os)
EXPORT(luaopen_package)
EXPORT(luaopen_string)
EXPORT(luaopen_table)
EXPORT(luaT_call)
EXPORT(luaT_checktuple)
EXPORT(luaT_cpcall)
EXPORT(luaT_error)
EXPORT(luaT_istuple)
EXPORT(luaT_pushtuple)
EXPORT(luaT_state)
EXPORT(luaT_tolstring)
EXPORT(luaT_tuple_encode)
EXPORT(luaT_tuple_new)
EXPORT(mp_char2escape)
EXPORT(mp_decode_double)
EXPORT(mp_decode_extl)
EXPORT(mp_decode_float)
EXPORT(mp_encode_decimal)
EXPORT(mp_encode_double)
EXPORT(mp_encode_float)
EXPORT(mp_encode_uuid)
EXPORT(mp_ext_hint)
EXPORT(mp_format)
EXPORT(mp_fprint)
EXPORT(mp_fprint_ext)
EXPORT(mp_fprint_ext_default)
EXPORT(mp_fprint_recursion)
EXPORT(mp_parser_hint)
EXPORT(mp_sizeof_decimal)
EXPORT(mp_sizeof_uuid)
EXPORT(mp_snprint)
EXPORT(mp_snprint_ext)
EXPORT(mp_snprint_ext_default)
EXPORT(mp_snprint_recursion)
EXPORT(mp_type_hint)
EXPORT(mp_vformat)
EXPORT(password_prepare)
EXPORT(PMurHash32)
EXPORT(PMurHash32_Process)
EXPORT(PMurHash32_Result)
EXPORT(port_destroy)
EXPORT(random_bytes)
EXPORT(_say)
EXPORT(say_logger_init)
EXPORT(say_logger_initialized)
EXPORT(say_logrotate)
EXPORT(say_parse_logger_type)
EXPORT(say_set_log_format)
EXPORT(say_set_log_level)
EXPORT(SHA1internal)
EXPORT(space_bsize)
EXPORT(space_by_id)
EXPORT(space_run_triggers)
EXPORT(string_strip_helper)
EXPORT(swim_add_member)
EXPORT(swim_broadcast)
EXPORT(swim_cfg)
EXPORT(swim_is_configured)
EXPORT(swim_iterator_close)
EXPORT(swim_iterator_next)
EXPORT(swim_iterator_open)
EXPORT(swim_member_by_uuid)
EXPORT(swim_member_incarnation)
EXPORT(swim_member_is_dropped)
EXPORT(swim_member_is_payload_up_to_date)
EXPORT(swim_member_payload)
EXPORT(swim_member_ref)
EXPORT(swim_member_status)
EXPORT(swim_member_unref)
EXPORT(swim_member_uri)
EXPORT(swim_member_uuid)
EXPORT(swim_probe_member)
EXPORT(swim_quit)
EXPORT(swim_remove_member)
EXPORT(swim_self)
EXPORT(swim_set_codec)
EXPORT(swim_set_payload)
EXPORT(swim_size)
EXPORT(tarantool_exit)
EXPORT(tarantool_lua_ibuf)
EXPORT(tarantool_lua_slab_cache)
EXPORT(tarantool_uptime)
EXPORT(title_get)
EXPORT(title_get_custom)
EXPORT(title_get_interpretor_name)
EXPORT(title_get_script_name)
EXPORT(title_get_status)
EXPORT(title_set_custom)
EXPORT(title_set_interpretor_name)
EXPORT(title_set_script_name)
EXPORT(title_set_status)
EXPORT(title_update)
EXPORT(tnt_iconv)
EXPORT(tnt_iconv_close)
EXPORT(tnt_iconv_open)
EXPORT(tt_uuid_bswap)
EXPORT(tt_uuid_create)
EXPORT(tt_uuid_from_string)
EXPORT(tt_uuid_is_equal)
EXPORT(tt_uuid_is_nil)
EXPORT(tt_uuid_str)
EXPORT(uri_format)
EXPORT(uri_parse)
EXPORT(uuid_nil)
EXPORT(uuid_unpack)
