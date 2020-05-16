#pragma once

#include <vector>

#include "AppTypes.h"
#include "AbstractBlackjackAction.h"
#include "Box.h"
#include "Card.h"
#include "Player.h"
#include "PlayerBetInputValidator.h"

class Application;

class AbstractBlackjack
{
private:
    Application* app;

    std::vector<AbstractBlackjackAction> actions;

    std::vector<Box> boxes;

    std::vector<Card> shoe;

    u16 shoeIndex = 0;

    std::vector<Card*> dealerCards = {};

public:
    std::vector<Box>& getBoxes();

    virtual std::vector<Card>& createShoe(u8 deckCount);

    std::vector<Card>& shuffleShoe();

    virtual std::vector<Box>& createBoxes(std::vector<Player>& players, u8 boxCount);

    virtual void requestBets();

    virtual void dealCardsToBoxes(u8 cardPerBox);

    virtual void dealCardsToDealer(u8 cardToDealer);

    std::vector<Card*>& getDealerCards();
};