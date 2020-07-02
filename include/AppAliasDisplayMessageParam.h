#pragma once

#ifdef BJ2020_TEST_MODE

#include "MockDisplayMessageParam.h"

using ADisplayMessageParam = MockDisplayMessageParam;

#else

#include "ConsoleDisplayMessageParam.h"

using ADisplayMessageParam = ConsoleDisplayMessageParam;

#endif

//#include "MockDisplayMessageParam.h"
//
//using ADisplayMessageParam = MockDisplayMessageParam;

