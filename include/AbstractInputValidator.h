#pragma once

#include <string>

#include "AppTypes.h"

template <typename T>
class AbstractInputValidator
{
public:
	virtual bool validateValue(const T& value) = 0;

	virtual std::string getErrorMessageId() = 0;

	virtual std::string getRequestMessageId() = 0;
};