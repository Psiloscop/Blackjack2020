#include "DoubleBlackjackAction.h"

std::string DoubleBlackjackAction::getName()
{
    return "Double";
}

bool DoubleBlackjackAction::execute(Box* currentBox)
{
    u32 currentBet = currentBox->getBet();

    currentBox->getPlayer().increaseCash(currentBet);
    currentBox->setBet(currentBet * 2);
    currentBox->giveCard(this->blackjack->getNextCard());

    return false;
}

bool DoubleBlackjackAction::isAvailable(Box* currentBox)
{
    u32 currentBet = currentBox->getBet();

    return currentBox->getHandCount() == 1 &&
        currentBox->getHandCardsCount() == 2 &&
        currentBox->getPlayer().getCash() >= currentBet;
}

