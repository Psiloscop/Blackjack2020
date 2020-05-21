# Adding test case executable
add_executable(BOX_UNIT_TEST ${BJ2020_TEST_DIR}/BoxUnitTest.cpp)

# Adding array source
target_link_libraries(BOX_UNIT_TEST
        APPLICATION_SOURCE
        ABSTRACT_BLACKJACK_SOURCE
        PLAYER_SOURCE
        BOX_SOURCE
        CARD_SOURCE)

# Standard linking to gtest stuff
target_link_libraries(BOX_UNIT_TEST gmock gtest gtest_main)