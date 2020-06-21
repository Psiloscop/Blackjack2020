#include "HitBlackjackAction.h"

std::string HitBlackjackAction::getName()
{
    return "Hit";
}

bool HitBlackjackAction::execute()
{
    auto& box = this->blackjack->getCurrentBox();

    box.giveCard(this->blackjack->getNextCard());

    return true;
}

bool HitBlackjackAction::isAvailable()
{
    return true;
}