#include "InsuranceBlackjackAction.h"

std::string InsuranceBlackjackAction::getName()
{
    return "Insurance";
}

bool InsuranceBlackjackAction::execute()
{
    auto& currentBox = this->blackjack->getCurrentBox();
    u8 currentBoxIndex = this->blackjack->getCurrentBoxIndex();

    this->blackjack->addInsuredBoxIndex(currentBoxIndex);

    currentBox.setBet(currentBox.getBet() / 2, true);

    return false;
}

bool InsuranceBlackjackAction::isAvailable()
{
    auto& dealerBox = this->blackjack->getDealerBox();
    auto& currentBox = this->blackjack->getCurrentBox();
    u8 currentBoxIndex = this->blackjack->getCurrentBoxIndex();

    return !this->blackjack->hasInsuredBoxIndex(currentBoxIndex) &&
        dealerBox.getHandCards().size() == 2 &&
        dealerBox.getHandCards()[0]->getCardLetter() == "A" &&
        currentBox.getHandCount() == 1 &&
        currentBox.getHandCardsCount() == 2 &&
        currentBox.getPlayer().getCash() >= currentBox.getBet() / 2;
}