# Adding test case executable
add_executable(LINEAR_ALLOCATOR_UNIT_TEST ${BJ2020_TEST_DIR}/CLinearAllocatorUnitTest.cpp)

# Adding linear allocator source
target_link_libraries(LINEAR_ALLOCATOR_UNIT_TEST EXCEPTION_SOURCE LINEAR_ALLOCATOR_SOURCE)

# Standard linking to gtest stuff
target_link_libraries(LINEAR_ALLOCATOR_UNIT_TEST gtest gtest_main)