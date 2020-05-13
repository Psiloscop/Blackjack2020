#pragma once

#include <string>
#include <vector>

#include "AbstractInputHandler.h"
#include "ConsoleInputAdapter.h"

class ConsoleInputHandler: public AbstractInputHandler<ConsoleInputAdapter>
{
};