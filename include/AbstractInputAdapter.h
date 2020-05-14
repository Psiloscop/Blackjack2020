#pragma once

#include "TemplateInputValidator.h"

template <typename T>
class AbstractInputAdapter
{
public:
    virtual T input() const = 0;
};