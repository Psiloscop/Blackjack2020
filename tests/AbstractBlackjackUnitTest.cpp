#ifndef C_ARRAY_UNIT_TEST_CPP_INCLUDED
#define C_ARRAY_UNIT_TEST_CPP_INCLUDED

#include "gtest/gtest.h"
#include "gmock/gmock.h"

#include <vector>
#include "AbstractBlackjack.h"
#include "Card.h"

MATCHER(CardEq, "") {
    Card* card1 = std::get<0>(arg);
    Card* card2 = std::get<1>(arg);

    return *card1 == *card2;
}

/**
 * Testing createShoe() method
 */
TEST(AbstractBlackjack, createShoe)
{
    auto abstractBlackjack = new AbstractBlackjack();
    u8 deckCount = 2;

    auto shoe = abstractBlackjack->createShoe(deckCount);

    // Make sure that size of created shoe is equal to count of 2 * 52
    EXPECT_EQ(shoe.size(), 52 * 2);

    std::vector<Card*> cards;

    for (u8 deckNumber = 1; deckNumber <= deckCount; deckNumber++)
    {
        for (u8 suitNumber = 1; suitNumber <= 4; suitNumber++)
        {
            for (u8 cardNumber = 2; cardNumber <= 14; cardNumber++)
            {
                cards.push_back(new Card(cardNumber, CardSuit(suitNumber)));
            }
        }
    }

    // Make sure that createShoe() processed correctly
    EXPECT_THAT(shoe, testing::Pointwise(CardEq(), cards));

    delete abstractBlackjack;
}

/**
 * Testing shuffleShoe() method
 */
TEST(AbstractBlackjack, shuffleShoe)
{
    auto abstractBlackjack = new AbstractBlackjack();
    u8 deckCount = 1;

    auto& shoe = abstractBlackjack->createShoe(deckCount);

    Card* cardEx1 = new Card(2, CardSuit(1));
    Card* cardEx2 = new Card(3, CardSuit(1));
    Card* cardEx3 = new Card(4, CardSuit(1));

    Card* card1 = shoe[0];
    Card* card2 = shoe[1];
    Card* card3 = shoe[2];

    // Check if cards are in their expected positions
    ASSERT_TRUE(*cardEx1 == *card1);
    ASSERT_TRUE(*cardEx2 == *card2);
    ASSERT_TRUE(*cardEx3 == *card3);

    abstractBlackjack->shuffleShoe();

    card1 = shoe[0];
    card2 = shoe[1];
    card3 = shoe[2];

    // Check if at least one card changed its position after shuffling
    ASSERT_TRUE(*cardEx1 != *card1 || *cardEx2 != *card2 || *cardEx3 != *card3);
}


#endif