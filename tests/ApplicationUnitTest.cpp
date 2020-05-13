#ifndef __APPLICATION_UNIT_TEST_CPP_INCLUDED__
#define __APPLICATION_UNIT_TEST_CPP_INCLUDED__

#include "gtest/gtest.h"
#include "gmock/gmock.h"

#include <vector>
#include <string>

#include "Application.h"
#include "Player.h"

#include "MockDisplayHandler.h"
#include "MockInputHandler.h"

/**
 * Player creation test
 *
 * @test init
 */
TEST(ApplicationUnitTest, createPlayer)
{
    MockInputHandler inputHandler;
    MockDisplayHandler displayHandler;

    Application app(inputHandler, displayHandler);

    std:: string playerName1 = "Test1";
    u32 playerCash1 = 500;
    app.createPlayer(playerName1, playerCash1);

    std:: string playerName2 = "Test2";
    u32 playerCash2 = 600;
    app.createPlayer(playerName2, playerCash2);

    Player& player1 = app.getPlayer(0);
    Player& player2 = app.getPlayer(1);

    EXPECT_TRUE(player1.getName() == playerName1 && player1.getCash() == playerCash1);
    EXPECT_TRUE(player2.getName() == playerName2 && player2.getCash() == playerCash2);
    EXPECT_THROW(app.getPlayer(3), std::out_of_range);

    player1.increaseCash(100);
    player2.decreaseCash(100);

    EXPECT_TRUE(app.getPlayer(0).getCash() == playerCash2);
    EXPECT_TRUE(app.getPlayer(1).getCash() == playerCash1);
}

#endif // __APPLICATION_UNIT_TEST_CPP_INCLUDED__