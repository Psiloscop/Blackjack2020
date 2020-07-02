#include "SplitBlackjackAction.h"

std::string SplitBlackjackAction::getName()
{
    return "Split";
}

bool SplitBlackjackAction::execute(Box* currentBox)
{
    auto handCards = currentBox->getHandCards();

    if (handCards.size() == 2 && handCards[0]->getCardLetter() == handCards[1]->getCardLetter())
    {
        u32 bet = currentBox->getBet();
        u8 prevHandNumber = currentBox->getCurrentHandNumber();
        u8 nextHandNumber = currentBox->getHandCount() + 1;

        currentBox->switchHand(nextHandNumber);
        currentBox->setBet(bet);
        currentBox->giveCard(handCards[1]);
        currentBox->giveCard(this->blackjack->getNextCard());
        currentBox->switchHand(prevHandNumber);
        currentBox->getHandCards().pop_back();
        currentBox->giveCard(this->blackjack->getNextCard());
    }

    return true;
}

bool SplitBlackjackAction::isAvailable(Box* currentBox)
{
    auto& handCards = currentBox->getHandCards();

    return handCards.size() == 2 && handCards[0]->getCardLetter() == handCards[1]->getCardLetter() &&
        currentBox->getPlayer().getCash() >= currentBox->getBet();
}

