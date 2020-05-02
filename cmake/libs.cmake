# Google test - begin

# This adds another subdirectory, which has 'project(gtest)'.
add_subdirectory(${BJ2020_LIB_DIR}/googletest-release-1.8.1)

# Include the gtest library. gtest_SOURCE_DIR is available due to 'project(gtest)' above.
include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})
include_directories(${gmock_SOURCE_DIR}/include ${gmock_SOURCE_DIR})

# Google test - end