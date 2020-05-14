#pragma once

#include <string>
#include <map>

#include "AppTypes.h"

class AbstractInputValidator
{
public:
	virtual std::map<std::string, std::string> getErrorMessageParams() = 0;

	virtual std::map<std::string, std::string> getRequestMessageParams() = 0;
};