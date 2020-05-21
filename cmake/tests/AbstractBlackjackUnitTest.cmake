# Adding test case executable
add_executable(ABSTRACT_BLACKJACK_UNIT_TEST ${BJ2020_TEST_DIR}/AbstractBlackjackUnitTest.cpp)

# Adding array source
target_link_libraries(ABSTRACT_BLACKJACK_UNIT_TEST
        APPLICATION_SOURCE
        ABSTRACT_BLACKJACK_SOURCE
        PLAYER_SOURCE
        DEALER_SOURCE
        BOX_SOURCE
        CARD_SOURCE)

# Standard linking to gtest stuff
target_link_libraries(ABSTRACT_BLACKJACK_UNIT_TEST gmock gtest gtest_main)