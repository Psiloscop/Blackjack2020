#include "SwitchHandBlackjackAction.h"

std::string SwitchHandBlackjackAction::getName()
{
    return "Switch hand";
}

bool SwitchHandBlackjackAction::execute()
{
    u8 currentHandNumber = this->blackjack->getCurrentBox().getCurrentHandNumber();
    auto playableHandNumbers = this->blackjack->getCurrentBox().getPlayableHandNumbers();

    if (currentHandNumber == playableHandNumbers[playableHandNumbers.size() - 1])
    {
        this->blackjack->getCurrentBox().switchHand(playableHandNumbers[0]);
    }
    else
    {
        auto it = std::find_if(playableHandNumbers.begin(), playableHandNumbers.end(),
                [currentHandNumber](const u8 number) { return number > currentHandNumber; });

        this->blackjack->getCurrentBox().switchHand(*it);
    }

    return true;
}

bool SwitchHandBlackjackAction::isAvailable()
{
    return this->blackjack->getCurrentBox().getPlayableHandNumbers().size() > 1;
}

