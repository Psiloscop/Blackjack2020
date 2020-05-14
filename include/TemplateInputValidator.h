#pragma once

#include <string>
#include <map>

#include "AbstractInputValidator.h"
#include "AppTypes.h"

template <typename T>
class TemplateInputValidator: public AbstractInputValidator
{
public:
	virtual bool validateValue(const T& value) = 0;
};