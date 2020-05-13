#pragma once

#include <vector>

#include "AppTypes.h"
#include "AbstractBlackjackAction.h"
#include "Box.h"
#include "Card.h"
#include "Player.h"

class Application;

class AbstractBlackjack
{
private:
    Application* app;

    std::vector<Box> boxes;

    std::vector<Card> shoe;

    std::vector<AbstractBlackjackAction> actions;

public:
    virtual std::vector<Card>& createShoe(u8 deckCount);

    std::vector<Card>& shuffleShoe();

    virtual std::vector<Box>& createBoxes(std::vector<Player>& players, u8 boxCount);
};