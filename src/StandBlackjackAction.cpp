#include "StandBlackjackAction.h"

std::string StandBlackjackAction::getName()
{
    return "Stand";
}

bool StandBlackjackAction::execute()
{
    return false;
}

bool StandBlackjackAction::isAvailable()
{
    return true;
}

