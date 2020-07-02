#pragma once

#include <string>

#include "AbstractBlackjack.h"

class Box;

class AbstractBlackjackAction
{
protected:
	AbstractBlackjack* blackjack;

public:
    AbstractBlackjackAction(AbstractBlackjack* blackjack)
        : blackjack{blackjack}
    {}

	virtual std::string	getName() = 0;

	virtual bool execute(Box*) = 0;

    virtual bool isAvailable(Box*) = 0;
};