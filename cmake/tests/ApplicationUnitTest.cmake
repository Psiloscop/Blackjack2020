# Adding test case executable
add_executable(APPLICATION_UNIT_TEST ${BJ2020_TEST_DIR}/ApplicationUnitTest.cpp)

# Adding array source
target_link_libraries(APPLICATION_UNIT_TEST
        APPLICATION_SOURCE
        PLAYER_SOURCE
        CARD_SOURCE)

# Standard linking to gtest stuff
target_link_libraries(APPLICATION_UNIT_TEST gmock gtest gtest_main)