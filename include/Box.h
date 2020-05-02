#ifndef __BOX_H_INCLUDED__
#define __BOX_H_INCLUDED__

class Player;

#include <vector>

#include "Player.h"
#include "Card.h"

class Box
{
private:
	Player* player;

	std::vector<Card> cards;

	unsigned short int activeHand = 1;
};

#endif // __BOX_H_INCLUDED__