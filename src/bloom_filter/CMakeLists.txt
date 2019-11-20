cmake_minimum_required(VERSION 3.14)



set(SRCs
    bloom_filter_test.c
    bloom_filter.c
    ../set/set.c
    ../hash/murmur3/murmur3.c
    ../buffer/buffer.c
)


include_directories(
        ../set
        ../hashable
        ../hash
        ../hash/murmur3
        ../buffer
    )





add_executable(bf_test ${SRCs})
add_definitions(-DMURMUR3)