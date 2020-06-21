#pragma once

#include <string>
#include <algorithm>

#include "AbstractBlackjackAction.h"

class InsuranceBlackjackAction: public AbstractBlackjackAction
{
public:
    using AbstractBlackjackAction::AbstractBlackjackAction;

	std::string	getName() override;

	bool execute() override;

	bool isAvailable() override;
};