#include "DoubleBlackjackAction.h"

std::string DoubleBlackjackAction::getName()
{
    return "Double";
}

bool DoubleBlackjackAction::execute()
{
    auto& currentBox = this->blackjack->getCurrentBox();
    u32 currentBet = currentBox.getBet();

    currentBox.getPlayer().decreaseCash(currentBet);
    currentBox.setBet(currentBet * 2);
    currentBox.giveCard(this->blackjack->getNextCard());

    return false;
}

bool DoubleBlackjackAction::isAvailable()
{
    auto& currentBox = this->blackjack->getCurrentBox();
    u32 currentBet = currentBox.getBet();

    return currentBox.getHandCount() == 1 &&
        currentBox.getHandCardsCount() == 2 &&
        currentBox.getPlayer().getCash() >= currentBet;
}

