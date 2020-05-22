#pragma once

#include <string>
#include "AbstractBlackjack.h"

class AbstractBlackjackAction
{
protected:
	AbstractBlackjack* blackjack;

public:
    AbstractBlackjackAction(AbstractBlackjack* blackjack)
        : blackjack{blackjack}
    {}

	virtual std::string	getName() = 0;

	virtual bool execute() = 0;
};