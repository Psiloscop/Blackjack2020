#pragma once

#include "TemplateInputHandler.h"
#include "MockInputAdapter.h"

class MockInputHandler: public TemplateInputHandler<MockInputAdapter>
{
};