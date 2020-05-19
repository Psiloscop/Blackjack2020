#pragma once

#include "AbstractBlackjack.h"

class MockAbstractBlackjack: public AbstractBlackjack
{
public:
    void prepareGame() override
    {}

    void playGame() override
    {}

    void finishGame() override
    {}
};