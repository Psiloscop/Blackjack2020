#pragma once

#include <vector>

#include "Player.h"
#include "Card.h"

class Box
{
protected:
    Player& player;

	std::vector<std::vector<Card*>> hands = {};

    std::vector<u32> bets = {0};

    u8 activeHand = 0;

public:
    Box(Player& player);

    void assignPlayer(Player&);

    void resetBox();

    Player& getPlayer() const;

    void giveCard(Card&);

    std::vector<Card*>& getHandCards(u8 = 1);

    void switchHand(u8);

    void setBet(u32);

    u32 getBet();
};