#pragma once

#ifdef BJ2020_TEST_MODE

#include "MockInputHandler.h"
#include "MockInputAdapter.h"
#include "MockDisplayHandler.h"
#include "MockDisplayEntity.h"

using AInputHandler = MockInputHandler;
using ADisplayHandler = MockDisplayHandler;
using ADisplayEntity = MockDisplayEntity;

#else

#include "ConsoleInputHandler.h"
#include "ConsoleInputAdapter.h"
#include "ConsoleDisplayHandler.h"
#include "ConsoleDisplayEntity.h"

using AInputHandler = ConsoleInputHandler;
using ADisplayHandler = ConsoleDisplayHandler;
using ADisplayEntity = ConsoleDisplayEntity;

#endif


//#include "MockInputHandler.h"
//#include "MockInputAdapter.h"
//#include "MockDisplayHandler.h"
//#include "MockDisplayEntity.h"
//
//using AInputHandler = MockInputHandler;
//using ADisplayHandler = MockDisplayHandler;
//using ADisplayEntity = MockDisplayEntity;

