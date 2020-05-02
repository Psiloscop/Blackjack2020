#include "Box.h"

void Box::assignPlayer(Player* pPlayer)
{
    this->player = pPlayer;
}

void Box::giveCard(Card* card)
{
    this->cards.push_back(card);
}