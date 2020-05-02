# Adding test case executable
add_executable(ARRAY_UNIT_TEST ${BJ2020_TEST_DIR}/CArrayUnitTest.cpp)

# Adding array source
target_link_libraries(ARRAY_UNIT_TEST LINEAR_ALLOCATOR_SOURCE EXCEPTION_SOURCE BASE_LINEAR_ALLOCATOR_SOURCE)

# Standard linking to gtest stuff
target_link_libraries(ARRAY_UNIT_TEST gtest gtest_main)