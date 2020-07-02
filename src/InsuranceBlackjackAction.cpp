#include "InsuranceBlackjackAction.h"

std::string InsuranceBlackjackAction::getName()
{
    return "Insurance";
}

bool InsuranceBlackjackAction::execute(Box* currentBox)
{
    u8 currentBoxIndex = this->blackjack->getBoxIndex(*currentBox);

    this->blackjack->addInsuredBoxIndex(currentBoxIndex);

    currentBox->setBet(currentBox->getBet() / 2, true);

    return false;
}

bool InsuranceBlackjackAction::isAvailable(Box* currentBox)
{
    auto& dealerBox = this->blackjack->getDealerBox();
    u8 currentBoxIndex = this->blackjack->getBoxIndex(*currentBox);

    return !this->blackjack->hasInsuredBoxIndex(currentBoxIndex) &&
        dealerBox.getHandCards().size() == 2 &&
        dealerBox.getHandCards()[0]->getCardLetter() == "A" &&
        currentBox->getHandCount() == 1 &&
        currentBox->getHandCardsCount() == 2 &&
        currentBox->getPlayer().getCash() >= currentBox->getBet() / 2;
}