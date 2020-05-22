#pragma once

#include <map>

#include "AbstractBlackjack.h"
#include "HitBlackjackAction.h"
#include "ActionInputValidator.h"

class AmericanBlackjack: public AbstractBlackjack
{
public:
    AmericanBlackjack();

    void prepareGame() override;

    void playGame() override;

    void finishGame() override;
};