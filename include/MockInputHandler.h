#pragma once

#include "AbstractInputHandler.h"
#include "MockInputAdapter.h"

class MockInputHandler: public AbstractInputHandler<MockInputAdapter>
{
};