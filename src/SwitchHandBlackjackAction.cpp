#include "SwitchHandBlackjackAction.h"

std::string SwitchHandBlackjackAction::getName()
{
    return "Switch hand";
}

bool SwitchHandBlackjackAction::execute(Box* currentBox)
{
    u8 currentHandNumber = currentBox->getCurrentHandNumber();
    auto playableHandNumbers = currentBox->getPlayableHandNumbers();

    if (currentHandNumber == playableHandNumbers[playableHandNumbers.size() - 1])
    {
        currentBox->switchHand(playableHandNumbers[0]);
    }
    else
    {
        auto it = std::find_if(playableHandNumbers.begin(), playableHandNumbers.end(),
                [currentHandNumber](const u8 number) { return number > currentHandNumber; });

        currentBox->switchHand(*it);
    }

    return true;
}

bool SwitchHandBlackjackAction::isAvailable(Box* currentBox)
{
    return currentBox->getPlayableHandNumbers().size() > 1;
}

