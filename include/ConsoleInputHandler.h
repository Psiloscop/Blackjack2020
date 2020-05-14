#pragma once

#include <string>
#include <vector>

#include "TemplateInputHandler.h"
#include "ConsoleInputAdapter.h"

class ConsoleInputHandler: public TemplateInputHandler<ConsoleInputAdapter>
{
};