# Adding test case executable
add_executable(SHARED_POINTER_UNIT_TEST ${BJ2020_TEST_DIR}/CSharedPointerUnitTest.cpp)

# Standard linking to gtest stuff
target_link_libraries(SHARED_POINTER_UNIT_TEST gtest gtest_main)