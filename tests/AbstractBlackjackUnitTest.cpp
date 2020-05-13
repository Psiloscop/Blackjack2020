#ifndef __ABSTRACT_BLACKJACK_UNIT_TEST_CPP_INCLUDED__
#define __ABSTRACT_BLACKJACK_UNIT_TEST_CPP_INCLUDED__

#include "gtest/gtest.h"
#include "gmock/gmock.h"

#include <vector>

#include "Application.h"
#include "AbstractBlackjack.h"
#include "MockDisplayHandler.h"
#include "MockInputHandler.h"
#include "Card.h"
#include "Box.h"

MATCHER(CardEq, "") {
    Card card1 = std::get<0>(arg);
    Card card2 = std::get<1>(arg);

    return card1 == card2;
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

    std::vector<Card> cards;

    for (u8 deckNumber = 1; deckNumber <= deckCount; deckNumber++)
    {
        for (u8 suitNumber = 1; suitNumber <= 4; suitNumber++)
        {
            for (u8 cardNumber = 2; cardNumber <= 14; cardNumber++)
            {
                Card card(cardNumber, CardSuit(suitNumber));

                cards.push_back(card);
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

    Card cardEx1(2, CardSuit(1));
    Card cardEx2(3, CardSuit(1));
    Card cardEx3(4, CardSuit(1));

    Card& card1 = shoe[0];
    Card& card2 = shoe[1];
    Card& card3 = shoe[2];

    // Check if cards are in their expected positions
    ASSERT_TRUE(cardEx1 == card1);
    ASSERT_TRUE(cardEx2 == card2);
    ASSERT_TRUE(cardEx3 == card3);

    abstractBlackjack->shuffleShoe();

    card1 = shoe[0];
    card2 = shoe[1];
    card3 = shoe[2];

    // Check if at least one card changed its position after shuffling
    ASSERT_TRUE(cardEx1 != card1 || cardEx2 != card2 || cardEx3 != card3);
}

/**
 * Testing createBoxes() method
 */
TEST(AbstractBlackjack, createBoxes)
{
    auto abstractBlackjack = new AbstractBlackjack();

    MockInputHandler inputHandler;
    MockDisplayHandler displayHandler;
    Application app(inputHandler, displayHandler);

    std::vector<Player> players = {
        Player(&app, "Test1", 250),
        Player(&app, "Test2", 500),
        Player(&app, "Test3", 750),
        Player(&app, "Test4", 1000),
    };
    u8 boxCount = 6; // Explicitly assigned bigger box count than player count

    auto& boxes = abstractBlackjack->createBoxes(players, boxCount);

    // Make sure that created boxed is equal to player count
    ASSERT_TRUE(boxes.size() == players.size());

    // Checks if changes to box list is applied
    ASSERT_TRUE(boxes[0].getPlayer().getName() == "Test1" && boxes[0].getPlayer().getCash() == 250);
    ASSERT_TRUE(boxes[1].getPlayer().getName() == "Test2" && boxes[1].getPlayer().getCash() == 500);
    ASSERT_TRUE(boxes[2].getPlayer().getName() == "Test3" && boxes[2].getPlayer().getCash() == 750);
    ASSERT_TRUE(boxes[3].getPlayer().getName() == "Test4" && boxes[3].getPlayer().getCash() == 1000);

    players[1].increaseCash(500);
    players[3].decreaseCash(500);

    // Check if player reference really works
    ASSERT_TRUE(boxes[1].getPlayer().getName() == "Test2" && boxes[1].getPlayer().getCash() == 1000);
    ASSERT_TRUE(boxes[3].getPlayer().getName() == "Test4" && boxes[3].getPlayer().getCash() == 500);
}

/**
 * Testing createBoxes() method
 */
TEST(AbstractBlackjack, createBoxesWithApp)
{
    auto abstractBlackjack = new AbstractBlackjack();

    MockInputHandler inputHandler;
    MockDisplayHandler displayHandler;
    Application app(inputHandler, displayHandler);

    app.createPlayer("Test1", 250);
    app.createPlayer("Test2", 500);
    app.createPlayer("Test3", 750);
    app.createPlayer("Test4", 1000);

    std::vector<Player>& players = app.getPlayers();
    u8 boxCount = 4;

    auto& boxes = abstractBlackjack->createBoxes(players, boxCount);

    ASSERT_TRUE(boxes[0].getPlayer().getName() == app.getPlayer(0).getName() &&
                boxes[0].getPlayer().getCash() == app.getPlayer(0).getCash());
    ASSERT_TRUE(boxes[1].getPlayer().getName() == app.getPlayer(1).getName() &&
                boxes[1].getPlayer().getCash() == app.getPlayer(1).getCash());
    ASSERT_TRUE(boxes[2].getPlayer().getName() == app.getPlayer(2).getName() &&
                boxes[2].getPlayer().getCash() == app.getPlayer(2).getCash());
    ASSERT_TRUE(boxes[3].getPlayer().getName() == app.getPlayer(3).getName() &&
                boxes[3].getPlayer().getCash() == app.getPlayer(3).getCash());

    players[1].increaseCash(500);
    players[3].decreaseCash(500);

    ASSERT_TRUE(boxes[1].getPlayer().getName() == app.getPlayer(1).getName() &&
                boxes[1].getPlayer().getCash() == app.getPlayer(1).getCash());
    ASSERT_TRUE(boxes[3].getPlayer().getName() == app.getPlayer(3).getName() &&
                boxes[3].getPlayer().getCash() == app.getPlayer(3).getCash());
}

#endif // __ABSTRACT_BLACKJACK_UNIT_TEST_CPP_INCLUDED__