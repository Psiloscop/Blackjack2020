#pragma once

#include <string>
#include <vector>

#include "AbstractInputHandler.h"

class ConsoleInputHandler: public AbstractInputHandler<ConsoleInputAdapter>
{
};