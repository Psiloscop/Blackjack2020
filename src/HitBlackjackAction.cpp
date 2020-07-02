#include "HitBlackjackAction.h"

std::string HitBlackjackAction::getName()
{
    return "Hit";
}

bool HitBlackjackAction::execute(Box* currentBox)
{
    currentBox->giveCard(this->blackjack->getNextCard());

    return true;
}

bool HitBlackjackAction::isAvailable(Box* currentBox)
{
    return true;
}