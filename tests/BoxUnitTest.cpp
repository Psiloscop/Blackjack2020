#ifndef __BOX_UNIT_TEST_CPP_INCLUDED__
#define __BOX_UNIT_TEST_CPP_INCLUDED__

#include "gtest/gtest.h"
#include "gmock/gmock.h"

#include <vector>

#include "Box.h"
#include "Card.h"
#include "Player.h"
#include "Application.h"
#include "MockAbstractBlackjack.h"
#include "MockDisplayHandler.h"
#include "MockInputHandler.h"

/**
 * Testing both assignPlayer() and getPlayer() method
 */
TEST(Box, assignPlayer_getPlayer)
{
    MockAbstractBlackjack game;
    MockInputHandler inputHandler;
    MockDisplayHandler displayHandler;
    Application app(game, inputHandler, displayHandler);

    Player player1(&app, "Test1", 500);
    Player player2(&app, "Test2", 1000);

    u8 allowedMaxValueForPlayer = 21;
    Box box(&player1, allowedMaxValueForPlayer);

    // Check if player in a box is the same
    EXPECT_EQ(box.getPlayer().getName(), player1.getName());

    box.assignPlayer(&player2);

    // Check if box's player changed
    EXPECT_EQ(box.getPlayer().getName(), player2.getName());
}

/**
 * Testing methods: giveCard(), getHandCardsCount()
 */
TEST(Box, giveCard_getHandCardsCount)
{
    MockAbstractBlackjack game;
    MockInputHandler inputHandler;
    MockDisplayHandler displayHandler;
    Application app(game, inputHandler, displayHandler);

    Player player(&app, "Test1", 500);
    Card card1(CardFace::jack, CardSuit::club);
    Card card2(CardFace::king, CardSuit::diamond);
    Card card3(CardFace::ace, CardSuit::heart);

    u8 allowedMaxValueForPlayer = 21;
    Box box(&player, allowedMaxValueForPlayer);

    // Check if newly-created box is card-free
    EXPECT_EQ(box.getHandCardsCount(), 0);

    box.giveCard(&card1);

    // Check if one card appeared on box
    EXPECT_EQ(box.getHandCardsCount(), 1);

    box.giveCard(&card2);

    // Check if another one card appeared on box
    EXPECT_EQ(box.getHandCardsCount(), 2);
}

/**
 * Testing getHandCardsValue() method
 */
TEST(Box, getHandCardsValue)
{
    MockAbstractBlackjack game;
    MockInputHandler inputHandler;
    MockDisplayHandler displayHandler;
    Application app(game, inputHandler, displayHandler);

    Player player(&app, "Test1", 500);
    Card card1(2, CardSuit::club);
    Card card2(5, CardSuit::diamond);
    Card card3(10, CardSuit::heart);
    Card card4(CardFace::queen, CardSuit::club);
    Card card5(CardFace::king, CardSuit::diamond);
    Card card6(CardFace::ace, CardSuit::heart);

    u8 allowedMaxValueForPlayer = 21;
    Box box(&player, allowedMaxValueForPlayer);

    box.giveCard(&card1);
    box.giveCard(&card2);
    box.giveCard(&card3);

    // Check if cards sum value corresponding expected value
    EXPECT_EQ(box.getHandCardsValue(), 17);

    box.resetBox();

    box.giveCard(&card4);
    box.giveCard(&card5);
    box.giveCard(&card6);

    // Check if cards sum value corresponding expected value
    EXPECT_EQ(box.getHandCardsValue(), 21);

    box.resetBox();

    box.giveCard(&card2);
    box.giveCard(&card2);
    box.giveCard(&card1);
    box.giveCard(&card6);
    box.giveCard(&card6);
    box.giveCard(&card6);

    // Check if cards sum value corresponding expected value
    EXPECT_EQ(box.getHandCardsValue(), 15);

    box.resetBox();

    box.giveCard(&card1);
    box.giveCard(&card2);
    box.giveCard(&card6);
    box.giveCard(&card6);
    box.giveCard(&card6);

    // Check if cards sum value corresponding expected value
    EXPECT_EQ(box.getHandCardsValue(), 20);


    // Dealer test case

    Dealer dealer;
    u8 allowedMaxValueForDealer = 17;
    Box dealerBox(&dealer, allowedMaxValueForPlayer);

    dealerBox.giveCard(&card5);
    dealerBox.giveCard(&card6);

    // Check if dealer has Blackjack his cards value is 21
    EXPECT_EQ(dealerBox.getHandCardsValue(), 21);
}

/**
 * Testing resetBox() method
 */
TEST(Box, resetBox)
{
    MockAbstractBlackjack game;
    MockInputHandler inputHandler;
    MockDisplayHandler displayHandler;
    Application app(game, inputHandler, displayHandler);

    Player player(&app, "Test1", 500);
    Card card1(CardFace::king, CardSuit::club);
    Card card2(CardFace::ace, CardSuit::heart);

    u8 allowedMaxValueForPlayer = 21;
    Box box(&player, allowedMaxValueForPlayer);

    box.setBet(250);
    box.giveCard(&card1);
    box.giveCard(&card2);

    // Check if bes is really set to box
    EXPECT_EQ(box.getBet(), 250);
    // Check if cards are really added to box
    EXPECT_EQ(box.getHandCardsCount(), 2);

    box.resetBox();

    // Check if bet was reset
    EXPECT_EQ(box.getBet(), 0);
    // Check if cards were removed
    EXPECT_EQ(box.getHandCardsCount(), 0);
}

/**
 * Testing switchHand() method
 */
TEST(Box, switchHand)
{
    MockAbstractBlackjack game;
    MockInputHandler inputHandler;
    MockDisplayHandler displayHandler;
    Application app(game, inputHandler, displayHandler);

    Player player(&app, "Test1", 500);
    Card card1(2, CardSuit::club);
    Card card2(5, CardSuit::diamond);
    Card card3(10, CardSuit::heart);

    u8 allowedMaxValueForPlayer = 21;
    Box box(&player, allowedMaxValueForPlayer);

    box.giveCard(&card1);
    box.giveCard(&card2);

    box.switchHand(2);

    box.giveCard(&card2);
    box.giveCard(&card3);

    // Check if cards were added to first (default) hand
    EXPECT_EQ(box.getHandCardsValue(), 15);

    box.switchHand(1);

    // Check if cards were added to second hand
    EXPECT_EQ(box.getHandCardsValue(), 7);

    // Check if switching to non-existing hand throws an exception
    EXPECT_THROW(box.switchHand(4), std::out_of_range);
}

/**
 * Testing both setBet() and getBet() methods
 */
TEST(Box, setBet_getBet)
{
    MockAbstractBlackjack game;
    MockInputHandler inputHandler;
    MockDisplayHandler displayHandler;
    Application app(game, inputHandler, displayHandler);

    Player player(&app, "Test1", 2000);
    Card card(CardFace::jack, CardSuit::spade);

    u8 allowedMaxValueForPlayer = 21;
    Box box(&player, allowedMaxValueForPlayer);

    box.setBet(500);
    box.giveCard(&card);

    // Check if user's cash has been decreased
    EXPECT_EQ(box.getPlayer().getCash(), 1500);
    // Check if bet was added on box for first hand
    EXPECT_EQ(box.getBet(), 500);

    box.switchHand(2);

    box.setBet(1000);
    box.giveCard(&card);

    // Check if user's cash has been decreased
    EXPECT_EQ(box.getPlayer().getCash(), 500);
    // Check if bet was added on box for second hand
    EXPECT_EQ(box.getBet(), 1000);

    box.switchHand(1);

    // Check if bet is still the same for first hand
    EXPECT_EQ(box.getBet(), 500);

    // Increase player's first hand bet. No replace!
    box.setBet(500, true);

    // Check if user's cash has been decreased
    EXPECT_EQ(box.getPlayer().getCash(), 0);
    // Check if bet has been increased, not replaced!
    EXPECT_EQ(box.getBet(), 1000);

    // Check if the method throws exception if player's cash is less than its bet
    EXPECT_THROW(box.setBet(100), std::overflow_error);
}

/**
 * Testing both updateBet() and getBet() methods
 */
TEST(Box, updateBet_getBet)
{
    MockAbstractBlackjack game;
    MockInputHandler inputHandler;
    MockDisplayHandler displayHandler;
    Application app(game, inputHandler, displayHandler);

    Player player(&app, "Test1", 1000);
    Card card(CardFace::jack, CardSuit::spade);

    u8 allowedMaxValueForPlayer = 21;
    Box box(&player, allowedMaxValueForPlayer);

    box.setBet(500);
    box.giveCard(&card);

    // Check if user's cash has been decreased
    EXPECT_EQ(box.getPlayer().getCash(), 500);
    // Check if bet was added
    EXPECT_EQ(box.getBet(), 500);

    box.updateBet(1000);

    // Check if user's cash is still the same as before bet
    EXPECT_EQ(box.getPlayer().getCash(), 500);
    // Check if bet was updated
    EXPECT_EQ(box.getBet(), 1000);
}

/**
 * Testing getAllBets() method
 */
TEST(Box, getAllBets)
{
    MockAbstractBlackjack game;
    MockInputHandler inputHandler;
    MockDisplayHandler displayHandler;
    Application app(game, inputHandler, displayHandler);

    Player player(&app, "Test1", 1000);
    Card card(CardFace::jack, CardSuit::spade);

    u8 allowedMaxValueForPlayer = 21;
    Box box(&player, allowedMaxValueForPlayer);

    box.setBet(500);
    box.giveCard(&card);

    // Check if bet was added
    EXPECT_EQ(box.getBet(), 500);
    // Check if sum of all bets is correct
    EXPECT_EQ(box.getAllBets(), 500);

    box.switchHand(2);
    box.setBet(500);
    box.giveCard(&card);

    // Check if bet was added for second hand
    EXPECT_EQ(box.getBet(), 500);
    // Check if sum of all bets is correct
    EXPECT_EQ(box.getAllBets(), 1000);
}

/**
 * Testing isBoxInSplit() method
 */
TEST(Box, isBoxInSplit)
{
    MockAbstractBlackjack game;
    MockInputHandler inputHandler;
    MockDisplayHandler displayHandler;
    Application app(game, inputHandler, displayHandler);

    Player player(&app, "Test1", 1500);
    Card card(CardFace::jack, CardSuit::spade);

    u8 allowedMaxValueForPlayer = 21;
    Box box(&player, allowedMaxValueForPlayer);

    box.setBet(500);
    box.giveCard(&card);

    // Check if box is not in split mode
    EXPECT_FALSE(box.isBoxInSplit());

    box.switchHand(2);
    box.setBet(1000);
    box.giveCard(&card);

    // Check if box is in split mode
    EXPECT_TRUE(box.isBoxInSplit());
}

/**
 * Testing hasBlackjack() method
 */
TEST(Box, hasBlackjack)
{
    MockAbstractBlackjack game;
    MockInputHandler inputHandler;
    MockDisplayHandler displayHandler;
    Application app(game, inputHandler, displayHandler);

    Player player(&app, "Test1", 1500);
    Card card1(CardFace::jack, CardSuit::spade);
    Card card2(CardFace::ace, CardSuit::spade);
    Card card3(CardFace::queen, CardSuit::spade);

    u8 allowedMaxValueForPlayer = 21;
    Box box(&player, allowedMaxValueForPlayer);

    box.setBet(500);
    box.giveCard(&card1);

    // Check if box has no blackjack combination
    EXPECT_FALSE(box.hasBlackjack());

    box.giveCard(&card2);

    // Check if box has blackjack combination after adding second card
    EXPECT_TRUE(box.hasBlackjack());

    box.switchHand(2);
    box.setBet(1000);
    box.giveCard(&card3);

    // Check if two or more hands discard blackjack combination
    EXPECT_FALSE(box.hasBlackjack());

    box.switchHand(1);

    // Check if two or more hands discard blackjack combination
    EXPECT_FALSE(box.hasBlackjack());
}

/**
 * Testing hasOvertake() method
 */
TEST(Box, hasOvertake)
{
    MockAbstractBlackjack game;
    MockInputHandler inputHandler;
    MockDisplayHandler displayHandler;
    Application app(game, inputHandler, displayHandler);

    Player player(&app, "Test1", 1500);
    Card card1(CardFace::jack, CardSuit::spade);
    Card card2(CardFace::queen, CardSuit::spade);
    Card card3(CardFace::king, CardSuit::spade);
    Card card4(CardFace::ace, CardSuit::spade);

    u8 allowedMaxValueForPlayer = 21;
    Box box(&player, allowedMaxValueForPlayer);

    box.setBet(500);
    box.giveCard(&card1);
    box.giveCard(&card2);

    // Check for overtake for sum 20
    EXPECT_FALSE(box.hasOvertake());

    box.switchHand(2);
    box.setBet(1000);
    box.giveCard(&card1);
    box.giveCard(&card2);
    box.giveCard(&card3);

    // Check for overtake on another hand for sum 30
    EXPECT_TRUE(box.hasOvertake());
    // Check for overtake on all hands
    EXPECT_FALSE(box.hasOvertake(true));

    box.switchHand(1);

    // Check for no overtake on default hand
    EXPECT_FALSE(box.hasOvertake());
    // Check for overtake on all hands
    EXPECT_FALSE(box.hasOvertake(true));

    box.giveCard(&card4);

    // Check for no overtake on default hand for sum 21
    EXPECT_FALSE(box.hasOvertake());
    // Check for overtake on all hands
    EXPECT_FALSE(box.hasOvertake(true));

    box.giveCard(&card1);

    // Check for overtake on default hand for sum 31
    EXPECT_TRUE(box.hasOvertake());
    // Check for overtake on all hands
    EXPECT_TRUE(box.hasOvertake(true));
}

/**
 * Testing getHandCount() method
 */
TEST(Box, getHandCount)
{
    MockAbstractBlackjack game;
    MockInputHandler inputHandler;
    MockDisplayHandler displayHandler;
    Application app(game, inputHandler, displayHandler);

    Player player(&app, "Test1", 500);

    u8 allowedMaxValueForPlayer = 21;
    Box box(&player, allowedMaxValueForPlayer);

    // Check if box has no hands because no cards were given
    EXPECT_EQ(box.getHandCount(), 0);

    Card card1(CardFace::jack, CardSuit::club);
    Card card2(CardFace::king, CardSuit::diamond);
    box.giveCard(&card1);
    box.giveCard(&card2);

    // Check if box has only one hand
    EXPECT_EQ(box.getHandCount(), 1);

    box.switchHand(2);

    // Check if box still has one hand because no card was given
    EXPECT_EQ(box.getHandCount(), 1);

    box.giveCard(&card1);
    box.giveCard(&card2);

    // Check if box now has two hands.
    EXPECT_EQ(box.getHandCount(), 2);

    box.switchHand(1);

    // Check if box has two hands after switching to first one
    EXPECT_EQ(box.getHandCount(), 2);
}

/**
 * Testing getCurrentHandNumber() method
 */
TEST(Box, getCurrentHandNumber)
{
    MockAbstractBlackjack game;
    MockInputHandler inputHandler;
    MockDisplayHandler displayHandler;
    Application app(game, inputHandler, displayHandler);

    Player player(&app, "Test1", 500);

    u8 allowedMaxValueForPlayer = 21;
    Box box(&player, allowedMaxValueForPlayer);

    // Check if current number of the box is 1
    EXPECT_EQ(box.getCurrentHandNumber(), 1);

    Card card1(CardFace::jack, CardSuit::club);
    Card card2(CardFace::king, CardSuit::diamond);
    box.giveCard(&card1);
    box.giveCard(&card2);

    box.switchHand(2);

    // Check if current number of the box is 2
    EXPECT_EQ(box.getCurrentHandNumber(), 2);

    box.switchHand(1);

    // Check if current number of the box is 1
    EXPECT_EQ(box.getCurrentHandNumber(), 1);
}

/**
 * Testing getCurrentHandNumber() method
 */
TEST(Box, isAllowedMaxValueReached)
{
    MockAbstractBlackjack game;
    MockInputHandler inputHandler;
    MockDisplayHandler displayHandler;
    Application app(game, inputHandler, displayHandler);

    Player player(&app, "Test1", 500);

    u8 allowedMaxValueForPlayer = 21;
    Box box(&player, allowedMaxValueForPlayer);

    Card card1(CardFace::jack, CardSuit::club);
    Card card2(CardFace::king, CardSuit::diamond);
    Card card3(1, CardSuit::spade);

    EXPECT_FALSE(box.isAllowedMaxValueReached());

    box.giveCard(&card1);

    EXPECT_FALSE(box.isAllowedMaxValueReached());

    box.giveCard(&card2);

    EXPECT_FALSE(box.isAllowedMaxValueReached());

    box.giveCard(&card3);

    EXPECT_TRUE(box.isAllowedMaxValueReached());
}

/**
 * Testing getPlayableHandNumbers() method
 */
TEST(Box, getPlayableHandNumbers)
{
    MockAbstractBlackjack game;
    MockInputHandler inputHandler;
    MockDisplayHandler displayHandler;
    Application app(game, inputHandler, displayHandler);

    Player player(&app, "Test1", 500);

    u8 allowedMaxValueForPlayer = 21;
    Box box(&player, allowedMaxValueForPlayer);

    Card card1(CardFace::jack, CardSuit::club);
    Card card2(CardFace::queen, CardSuit::diamond);
    Card card3(CardFace::king, CardSuit::spade);

    box.switchHand(1);
    box.giveCard(&card1);
    box.switchHand(2);
    box.giveCard(&card1);
    box.switchHand(3);
    box.giveCard(&card1);

    ASSERT_THAT(box.getPlayableHandNumbers(), ::testing::ElementsAre(1, 2, 3));

    box.switchHand(1);
    box.giveCard(&card2);
    box.giveCard(&card3);

    ASSERT_THAT(box.getPlayableHandNumbers(), ::testing::ElementsAre(2, 3));

    box.switchHand(2);
    box.giveCard(&card2);
    box.giveCard(&card3);

    ASSERT_THAT(box.getPlayableHandNumbers(), ::testing::ElementsAre(3));

    box.switchHand(3);
    box.giveCard(&card2);
    box.giveCard(&card3);

    ASSERT_THAT(box.getPlayableHandNumbers(), ::testing::ElementsAre());
}

#endif // __BOX_UNIT_TEST_CPP_INCLUDED__