#include "SplitBlackjackAction.h"

std::string SplitBlackjackAction::getName()
{
    return "Split";
}

bool SplitBlackjackAction::execute()
{
    auto& currentBox = this->blackjack->getCurrentBox();
    auto& handCards = currentBox.getHandCards();

    if (handCards.size() == 2 && *handCards[0] == *handCards[1])
    {
        u32 bet = currentBox.getBet();

        currentBox.getPlayer().decreaseCash(bet);
        currentBox.switchHand(currentBox.getCurrentHandNumber() + 1);
        currentBox.setBet(bet);
        currentBox.giveCard(handCards[1]);
        currentBox.switchHand(currentBox.getCurrentHandNumber() - 1);

        handCards.pop_back();
    }

    return true;
}

bool SplitBlackjackAction::isAvailable()
{
    auto& currentBox = this->blackjack->getCurrentBox();
    auto& handCards = currentBox.getHandCards();

    return handCards.size() == 2 && *handCards[0] == *handCards[1] &&
        currentBox.getPlayer().getCash() >= currentBox.getBet();
}

