#ifndef __ABSTRACT_BLACKJACK_UNIT_TEST_CPP_INCLUDED__
#define __ABSTRACT_BLACKJACK_UNIT_TEST_CPP_INCLUDED__

#include "gtest/gtest.h"
#include "gmock/gmock.h"

#include <utility>
#include <vector>

#include "Application.h"
#include "MockAbstractBlackjack.h"
#include "MockDisplayHandler.h"
#include "MockInputHandler.h"
#include "MockInputAdapter.h"
#include "Card.h"
#include "Box.h"

MATCHER(CardEq, "")
{
    Card card1 = std::get<0>(arg);
    Card card2 = std::get<1>(arg);

    return card1 == card2;
}

/**
 * Testing createShoe() method
 */
TEST(AbstractBlackjack, createShoe)
{
    auto abstractBlackjack = new MockAbstractBlackjack();

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
    auto abstractBlackjack = new MockAbstractBlackjack();

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
    MockAbstractBlackjack game;
    MockInputHandler inputHandler;
    MockDisplayHandler displayHandler;
    Application app(game, inputHandler, displayHandler);

    std::vector<Player> players = {
        Player(&app, "Test1", 250),
        Player(&app, "Test2", 500),
        Player(&app, "Test3", 750),
        Player(&app, "Test4", 1000),
    };
    u8 boxCount = 6; // Explicitly assigned bigger box count than player count

    auto& boxes = game.createBoxes(players, boxCount);

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
    MockAbstractBlackjack game;
    MockInputHandler inputHandler;
    MockDisplayHandler displayHandler;
    Application app(game, inputHandler, displayHandler);

    app.createPlayer("Test1", 250);
    app.createPlayer("Test2", 500);
    app.createPlayer("Test3", 750);
    app.createPlayer("Test4", 1000);

    std::vector<Player>& players = app.getPlayers();
    u8 boxCount = players.size();

    auto& boxes = game.createBoxes(players, boxCount);

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

/**
 * Testing dealCardsToBoxes() method
 */
TEST(AbstractBlackjack, dealCardsToBoxes)
{
    MockAbstractBlackjack game;
    MockInputHandler inputHandler;
    MockDisplayHandler displayHandler;
    Application app(game, inputHandler, displayHandler);

    app.createPlayer("Test1", 250);
    app.createPlayer("Test2", 500);

    auto& shoe = game.createShoe(1);
    game.createBoxes(app.getPlayers(), 2);
    game.dealCardsToBoxes(2);
    auto& boxes = game.getBoxes();
    auto& cards1 = boxes[0].getHandCards();
    auto& cards2 = boxes[1].getHandCards();

    EXPECT_TRUE(*cards1[0] == shoe[0]);
    EXPECT_TRUE(*cards1[1] == shoe[1]);
    EXPECT_TRUE(*cards2[0] == shoe[2]);
    EXPECT_TRUE(*cards2[1] == shoe[3]);
}

/**
 * Testing both dealCardsToDealer() and getDealerCards() method
 */
TEST(AbstractBlackjack, dealCardsToDealer_getDealerCards)
{
    MockAbstractBlackjack game;
    MockInputHandler inputHandler;
    MockDisplayHandler displayHandler;
    Application app(game, inputHandler, displayHandler);

    app.createPlayer("Test1", 250);
    std::vector<Player>& players = app.getPlayers();
    game.createBoxes(players, 1);
    auto& shoe = game.createShoe(1);

    game.dealCardsToDealer(2);
    auto& dealerCards = game.getDealerCards();

    EXPECT_TRUE(*dealerCards[0] == shoe[0]);
    EXPECT_TRUE(*dealerCards[1] == shoe[1]);
}

/**
 * Testing payToPlayerForBlackjack() method
 */
TEST(AbstractBlackjack, payToPlayerForBlackjack)
{
    MockAbstractBlackjack game;
    MockInputHandler inputHandler;
    MockDisplayHandler displayHandler;
    Application app(game, inputHandler, displayHandler);

    app.createPlayer("Test1", 1000);
    std::vector<Player>& players = app.getPlayers();
    auto& box = game.createBoxes(players, 1)[0];
    auto& player = box.getPlayer();

    EXPECT_TRUE(player.getCash() == 1000);

    box.setBet(1000);

    EXPECT_TRUE(player.getCash() == 0);

    game.payToPlayerForBlackjack(&box);

    EXPECT_TRUE(player.getCash() == 2500);
}

/**
 * Testing payToPlayerForCommonWin() method
 */
TEST(AbstractBlackjack, payToPlayerForCommonWin)
{
    MockAbstractBlackjack game;
    MockInputHandler inputHandler;
    MockDisplayHandler displayHandler;
    Application app(game, inputHandler, displayHandler);

    app.createPlayer("Test1", 1000);
    std::vector<Player>& players = app.getPlayers();
    auto& box = game.createBoxes(players, 1)[0];
    auto& player = box.getPlayer();

    EXPECT_TRUE(player.getCash() == 1000);

    box.setBet(1000);

    EXPECT_TRUE(player.getCash() == 0);

    game.payToPlayerForCommonWin(&box);

    EXPECT_TRUE(player.getCash() == 2000);
}

/**
 * Testing returnToPlayerItsBet() method
 */
TEST(AbstractBlackjack, returnToPlayerItsBet)
{
    MockAbstractBlackjack game;
    MockInputHandler inputHandler;
    MockDisplayHandler displayHandler;
    Application app(game, inputHandler, displayHandler);

    app.createPlayer("Test1", 1000);
    std::vector<Player>& players = app.getPlayers();
    auto& box = game.createBoxes(players, 1)[0];
    auto& player = box.getPlayer();

    EXPECT_TRUE(player.getCash() == 1000);

    box.setBet(1000);

    EXPECT_TRUE(player.getCash() == 0);

    game.returnToPlayerItsBet(&box);

    EXPECT_TRUE(player.getCash() == 1000);
}
/**
 * Testing getBoxIndex() method
 */
TEST(AbstractBlackjack, getBoxIndex)
{
    MockAbstractBlackjack game;
    MockInputHandler inputHandler;
    MockDisplayHandler displayHandler;
    Application app(game, inputHandler, displayHandler);

    app.createPlayer("Test1", 250);
    app.createPlayer("Test2", 500);
    app.createPlayer("Test3", 750);
    app.createPlayer("Test4", 1000);

    game.createBoxes(app.getPlayers(), app.getPlayers().size());

    auto& box1 = game.getBoxes()[0];
    auto& box2 = game.getBoxes()[1];
    auto& box3 = game.getBoxes()[2];
    auto& box4 = game.getBoxes()[3];

    // Check if box1 index is 0
    EXPECT_EQ(game.getBoxIndex(box1), 0);

    // Check if box2 index is 1
    EXPECT_EQ(game.getBoxIndex(box2), 1);

    // Check if box3 index is 2
    EXPECT_EQ(game.getBoxIndex(box3), 2);

    // Check if box4 index is 3
    EXPECT_EQ(game.getBoxIndex(box4), 3);
}

/**
 * Testing getNextCard() method
 */
TEST(AbstractBlackjack, getNextCard)
{
    MockAbstractBlackjack game;
    MockInputHandler inputHandler;
    MockDisplayHandler displayHandler;
    Application app(game, inputHandler, displayHandler);

    app.createPlayer("Test1", 250);

    auto& shoe = game.createShoe(1);
    auto& boxes = game.createBoxes(app.getPlayers(), 1);

    boxes[0].giveCard(game.getNextCard());
    boxes[0].giveCard(game.getNextCard());
    boxes[0].giveCard(game.getNextCard());
    boxes[0].giveCard(game.getNextCard());

    auto& cards = boxes[0].getHandCards();

    EXPECT_TRUE(*cards[0] == shoe[0]);
    EXPECT_TRUE(*cards[1] == shoe[1]);
    EXPECT_TRUE(*cards[2] == shoe[2]);
    EXPECT_TRUE(*cards[3] == shoe[3]);
}

/**
 * Testing shouldShoeBeReassembled() method
 */
TEST(AbstractBlackjack, shouldShoeBeReassembled)
{
    MockAbstractBlackjack game;
    MockInputHandler inputHandler;
    MockDisplayHandler displayHandler;
    Application app(game, inputHandler, displayHandler);

    app.createPlayer("Test1", 250);

    auto& shoe = game.createShoe(1);
    auto& box = game.createBoxes(app.getPlayers(), app.getPlayers().size())[0];

    u8 cardCount = shoe.size(); // 52
    u8 minCardCountToPlay = 6;
    u8 playerCount = app.getPlayers().size();

    EXPECT_FALSE(game.shouldShoeBeReassembled(playerCount));

    box.resetBox();

    for (u16 cardNumber = 0; cardNumber <= cardCount - minCardCountToPlay; cardNumber++)
    {
        box.giveCard(game.getNextCard());
    }

    EXPECT_TRUE(game.shouldShoeBeReassembled(playerCount));



    shoe = game.createShoe(1);
    cardCount = shoe.size();
    minCardCountToPlay = 12;
    playerCount = 2;

    EXPECT_FALSE(game.shouldShoeBeReassembled(playerCount));

    box.resetBox();

    for (u16 cardNumber = 0; cardNumber <= cardCount - minCardCountToPlay; cardNumber++)
    {
        box.giveCard(game.getNextCard());
    }

    EXPECT_TRUE(game.shouldShoeBeReassembled(playerCount));



    shoe = game.createShoe(2);
    cardCount = shoe.size();
    minCardCountToPlay = 6;
    playerCount = 1;

    EXPECT_FALSE(game.shouldShoeBeReassembled(playerCount));

    box.resetBox();

    for (u16 cardNumber = 0; cardNumber <= cardCount - minCardCountToPlay; cardNumber++)
    {
        box.giveCard(game.getNextCard());
    }

    EXPECT_TRUE(game.shouldShoeBeReassembled(playerCount));



    shoe = game.createShoe(2);
    cardCount = shoe.size();
    minCardCountToPlay = 12;
    playerCount = 2;

    EXPECT_FALSE(game.shouldShoeBeReassembled(playerCount));

    box.resetBox();

    for (u16 cardNumber = 0; cardNumber <= cardCount - minCardCountToPlay; cardNumber++)
    {
        box.giveCard(game.getNextCard());
    }

    EXPECT_TRUE(game.shouldShoeBeReassembled(playerCount));
}

// Commented because Gmock is fucked up
//
//class MockPlayer: public Player
//{
//public:
//    using Player::Player;
//
//    MOCK_CONST_METHOD0(requestBet, u32());
//};
//
//class MockBox: public Box
//{
//protected:
//    MockPlayer* mPlayer;
//
//public:
//    MockBox(u8 allowedMaxValue = 21) : Box(allowedMaxValue) {}
//};
//
//class MockMockAbstractBlackjack: public MockAbstractBlackjack
//{
//protected:
//    std::vector<MockBox> mockBoxes;
//
//public:
//    MockMockAbstractBlackjack() = default;
//
//    void assignBoxes(std::vector<MockBox> _mockBoxes)
//    {
//        this->mockBoxes = std::move(_mockBoxes);
//    }
//
//    MOCK_METHOD0(getBoxes, std::vector<MockBox>&());
//
//    std::vector<MockBox>& mockGetBoxes()
//    {
//        return this->mockBoxes;
//    }
//
//    void delegateBoxGetterToFake()
//    {
//        ON_CALL(*this, getBoxes())
//                .WillByDefault(::testing::Invoke(this, &MockMockAbstractBlackjack::mockGetBoxes));
//    }
//};
//
//class MockApplication: public Application
//{
//public:
//    using Application::Application;
//
//    MOCK_METHOD2(createPlayer, void(const std::string& playerName, u32 playerCash));
//
//    void mockCreatePlayer(const std::string& playerName, u32 playerCash)
//    {
//        MockPlayer player(this, playerName, playerCash);
//
//        this->players.push_back(std::move(player));
//    }
//
//    void delegatePlayerCreationToFake()
//    {
//        ON_CALL(*this, createPlayer(::testing::_, ::testing::_))
//                .WillByDefault(::testing::Invoke(this, &MockApplication::mockCreatePlayer));
//    }
//};
//
///**
// * Testing requestBets() method
// */
//TEST(AbstractBlackjack, requestBets)
//{
//    MockMockAbstractBlackjack game;
//    MockInputHandler inputHandler;
//    MockDisplayHandler displayHandler;
//    MockApplication app(game, inputHandler, displayHandler);
//
//    app.delegatePlayerCreationToFake();
//    EXPECT_CALL(app, createPlayer("Test1", 500));
//    app.createPlayer("Test1", 500);
//
//    auto& mockPlayer = static_cast<MockPlayer&>(app.getPlayer(0));
//    MockBox box(0);
//    box.assignPlayer(&mockPlayer);
//
//    game.delegateBoxGetterToFake();
//    EXPECT_CALL(game, getBoxes());
//    std::vector<MockBox> boxes = {box};
//    game.assignBoxes(boxes);
//
//    auto& player = static_cast<MockPlayer&>(box.getPlayer());
//
//    EXPECT_CALL(player, requestBet())
//            .WillOnce(::testing::Return(250));
//
//    game.requestBets();
//}

#endif // __ABSTRACT_BLACKJACK_UNIT_TEST_CPP_INCLUDED__