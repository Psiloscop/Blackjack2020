#pragma once

#include <vector>

#include "Player.h"
#include "Card.h"

enum BoxStatus
{
    ok,
    overtook,
    blackjack,
};

class Box
{
protected:
    Player& player;

	std::vector<std::vector<Card*>> hands = {};

    std::vector<u32> bets = {0};

    u8 allowedMaxValue = 21;

    u8 activeHand = 0;

public:
    Box(Player&, u8);

    void assignPlayer(Player&);

    void resetBox();

    Player& getPlayer() const;

    void giveCard(Card*);

    std::vector<std::vector<Card*>>& getAllCards();

    std::vector<Card*>& getHandCards();

    u8 getHandCardsCount();

    u8 getHandCardsValue();

    void switchHand(u8);

    void setBet(u32);

    u32 getBet();

    bool isBoxInSplit();

    bool hasBlackjack();

    bool hasOvertake();
};