#include "CardsDisplayEntity.h"

void CardsDisplayEntity::setCardsToDisplay(ADisplayHandler& displayHandler, const std::vector<Card*> _cards)
{
    this->cards = _cards;
}