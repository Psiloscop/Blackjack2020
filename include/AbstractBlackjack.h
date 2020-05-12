#pragma once

#include <vector>

#include "Application.h"
#include "AppTypes.h"
#include "AbstractBlackjackAction.h"
#include "Box.h"
#include "Card.h"

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
};