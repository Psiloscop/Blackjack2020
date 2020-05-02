# Adding test case executable
add_executable(STRING_UNIT_TEST ${BJ2020_TEST_DIR}/CStringUnitTest.cpp)

# Adding string source
target_link_libraries(STRING_UNIT_TEST STRING_SOURCE LINEAR_ALLOCATOR_SOURCE EXCEPTION_SOURCE BASE_LINEAR_ALLOCATOR_SOURCE)

# Standard linking to gtest stuff
target_link_libraries(STRING_UNIT_TEST gtest gtest_main)