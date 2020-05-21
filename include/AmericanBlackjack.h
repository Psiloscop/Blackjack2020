#pragma once

#include "AbstractBlackjack.h"

class AmericanBlackjack: public AbstractBlackjack
{
public:
    void prepareGame() override;

    void playGame() override;

    void finishGame() override;
};