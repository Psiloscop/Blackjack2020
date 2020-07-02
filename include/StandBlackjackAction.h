#pragma once

#include <string>

#include "AbstractBlackjackAction.h"

class StandBlackjackAction: public AbstractBlackjackAction
{
public:
    using AbstractBlackjackAction::AbstractBlackjackAction;

	std::string	getName() override;

	bool execute(Box*) override;

	bool isAvailable(Box*) override;
};