#pragma once

#include <map>

#include "AbstractBlackjack.h"
#include "HitBlackjackAction.h"
#include "OptionInputValidator.h"

class AmericanBlackjack: public AbstractBlackjack
{
protected:
    u8 chooseAction();

public:
    AmericanBlackjack();

    void prepareGame() override;

    void playGame() override;

    void finishGame() override;
};