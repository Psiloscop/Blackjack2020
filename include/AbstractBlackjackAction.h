#pragma once

class AbstractBlackjack;

#include <string>

class AbstractBlackjackAction
{
private:
	AbstractBlackjack* blackjack;

public:
	virtual std::string	getName() = 0;

	virtual bool execute() = 0;
};