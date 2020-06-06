#pragma once

#include <string>
#include <map>

#include "AbstractInputValidator.h"
#include "AppTypes.h"

template <typename T>
class TemplateInputValidator: public AbstractInputValidator
{
protected:
    T value;

public:
    virtual bool validateValue(const T& value) = 0;
    virtual T getValue() = 0;
};