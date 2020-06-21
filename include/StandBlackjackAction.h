#pragma once

#include <string>

#include "AbstractBlackjackAction.h"

class StandBlackjackAction: public AbstractBlackjackAction
{
public:
    using AbstractBlackjackAction::AbstractBlackjackAction;

	std::string	getName() override;

	bool execute() override;

	bool isAvailable() override;
};