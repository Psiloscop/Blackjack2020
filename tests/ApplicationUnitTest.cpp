#ifndef __APPLICATION_UNIT_TEST_CPP_INCLUDED__
#define __APPLICATION_UNIT_TEST_CPP_INCLUDED__

#include "gtest/gtest.h"
#include "gmock/gmock.h"

#include <vector>
#include <string>

#include "Application.h"
#include "ConsoleInputHandler.h"
#include "AbstractInputAdapter.h"
#include "AbstractDisplayEntity.h"
#include "Player.h"

template <typename T>
class MockInputAdapter: public AbstractInputAdapter<T>
{
public:
    T input() const
    {
        return T();
    }
};

class MockDisplayEntity: public AbstractDisplayEntity<std::string>
{
public:
    std::string& getDisplayEntity() override
    {
    }
};

class MockDisplayHandler: public AbstractDisplayHandler<MockDisplayEntity>
{
public:
    void display(MockDisplayEntity*) const override
    {
    }

    void displayBatch(std::vector<MockDisplayEntity*>) const override
    {
    }
};

/**
 * Player creation test
 *
 * @test init
 */
TEST(ApplicationUnitTest, createPlayer)
{
    Application<InputHandler, MockInputAdapter, MockDisplayHandler, MockDisplayEntity> app;

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