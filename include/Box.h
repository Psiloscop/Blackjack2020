#pragma once

#include <vector>

#include "Player.h"
#include "Card.h"

class Box
{
private:
    Player& player;

	std::vector<Card> cards;

	unsigned short int activeHand = 1;

public:
    Box(Player& player);

    void assignPlayer(Player&);

    Player& getPlayer();

    void giveCard(Card&);

    Box();
};