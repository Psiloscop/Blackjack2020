#pragma once

#include <string>

#include "AbstractBlackjackAction.h"

class SplitBlackjackAction: public AbstractBlackjackAction
{
public:
    using AbstractBlackjackAction::AbstractBlackjackAction;

	std::string	getName() override;

	bool execute() override;

	bool isAvailable() override;
};