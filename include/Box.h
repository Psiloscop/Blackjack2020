#pragma once

#include <vector>

#include "Player.h"
#include "Card.h"

class Box
{
private:
    Player& player;

	std::vector<std::vector<Card>> cards;

	u8 activeHand = 0;

	u32 bet = 0;

public:
    Box(Player& player);

    void assignPlayer(Player&);

    Player& getPlayer();

    void giveCard(Card&);

    Box();
};