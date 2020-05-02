# Adding test case executable
add_executable(ABSTRACT_BLACKJACK_UNIT_TEST ${BJ2020_TEST_DIR}/AbstractBlackjackUnitTest.cpp)

# Adding array source
target_link_libraries(ABSTRACT_BLACKJACK_UNIT_TEST
        ABSTRACT_BLACKJACK_SOURCE
        CARD_SOURCE)

# Standard linking to gtest stuff
target_link_libraries(ABSTRACT_BLACKJACK_UNIT_TEST gmock gtest gtest_main)