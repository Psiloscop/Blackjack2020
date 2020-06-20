#include "HitBlackjackAction.h"

std::string HitBlackjackAction::getName()
{
    return "Hit";
}

bool HitBlackjackAction::execute()
{
    Box& box = this->blackjack->getCurrentBox();

    box.giveCard(this->blackjack->getNextCard());

    return true;
}

