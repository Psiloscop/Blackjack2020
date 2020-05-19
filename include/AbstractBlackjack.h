#pragma once

#include <vector>

#include "AppTypes.h"
#include "AbstractBlackjackAction.h"
#include "Box.h"
#include "Card.h"
#include "Player.h"
#include "PlayerBetInputValidator.h"

enum RoundResult
{
    win,
    lose,
    tie
};

class Application;

class AbstractBlackjack
{
protected:
    Application* app;

    std::vector<AbstractBlackjackAction> actions;

    std::vector<Box> boxes;

    std::vector<Card> shoe;

    Box* dealerBox;

    u16 shoeIndex = 0;

    u8 boxIndex = 0;

    u8 allowedMaxValueForPlayer = 21;

    u8 allowedMaxValueForDealer= 17;

public:
    virtual void prepareGame() = 0;

    virtual void playGame() = 0;

    virtual void finishGame() = 0;

    std::vector<Box>& getBoxes();

    Box& getDealerBox();

    virtual std::vector<Card>& createShoe(u8 deckCount);

    std::vector<Card>& shuffleShoe();

    virtual std::vector<Box>& createBoxes(std::vector<Player>& players, u8 boxCount);

    virtual void requestBets();

    virtual void dealCardsToBoxes(u8 cardPerBox);

    virtual void dealCardsToDealer(u8 cardToDealer);

    std::vector<Card*>& getDealerCards();

    virtual BoxStatus getBoxStatus();

    virtual RoundResult getRoundResult();

    virtual void payToPlayerForBlackjack();

    virtual void payToPlayerForCommonWin();

    virtual void returnToPlayerItsBet();
};