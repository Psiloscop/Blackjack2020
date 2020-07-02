#include "StandBlackjackAction.h"

std::string StandBlackjackAction::getName()
{
    return "Stand";
}

bool StandBlackjackAction::execute(Box*)
{
    return false;
}

bool StandBlackjackAction::isAvailable(Box*)
{
    return true;
}

