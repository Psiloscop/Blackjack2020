#ifndef __ABSTRACT_BLACKJACK_ACTION_H_INCLUDED__
#define __ABSTRACT_BLACKJACK_ACTION_H_INCLUDED__

class AbstractBlackjack;

#include <string>

#include "AbstractBlackjack.h"

class AbstractBlackjackAction
{
private:
	AbstractBlackjack* blackjack;

public:
	virtual std::string	getName() = 0;

	virtual bool execute() = 0;
};

#endif // __ABSTRACT_BLACKJACK_ACTION_H_INCLUDED__