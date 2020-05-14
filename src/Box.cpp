#include "Box.h"

Box::Box(Player& player)
    : player(player)
{}

void Box::assignPlayer(Player& _player)
{
    this->player = _player;
}

Player& Box::getPlayer()
{
    return this->player;
}


void Box::giveCard(Card& card)
{
    this->cards[this->activeHand].push_back(card);
}