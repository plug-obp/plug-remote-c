cmake_minimum_required(VERSION 3.14)

set(SRCs
        hashtable_test_main.c
        linear_scan.c
        ../hash/murmur3/murmur3.c
        ../buffer/buffer.c
        )


include_directories(
        ../hashable
        ../hash
        ../hash/murmur3
        ../buffer
)



add_executable(test_hashtable ${SRCs})
add_definitions(-DMURMUR3)
set_target_properties(test_hashtable PROPERTIES COMPILE_FLAGS "-m32" LINK_FLAGS "-m32")