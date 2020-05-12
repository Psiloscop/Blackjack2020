#pragma once

//class Player;

#include <vector>

#include "Player.h"
#include "Card.h"

class Box
{
private:
	Player* player;

	std::vector<Card*> cards;

	unsigned short int activeHand = 1;

public:

    void assignPlayer(Player*);

    void giveCard(Card*);
};