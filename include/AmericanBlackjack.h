#pragma once

#include <map>
#include <numeric>

#include "AbstractBlackjack.h"
#include "OptionInputValidator.h"
#include "HitBlackjackAction.h"
#include "StandBlackjackAction.h"
#include "DoubleBlackjackAction.h"
#include "InsuranceBlackjackAction.h"
#include "SplitBlackjackAction.h"
#include "SwitchHandBlackjackAction.h"

class AmericanBlackjack: public AbstractBlackjack
{
protected:
    const u8 deckCount = 6;

public:
    AmericanBlackjack();

    void prepareGame() override;

    void playGame() override;

    void finishGame() override;
};