#pragma once

#include "AbstractInputValidator.h"

template <typename T>
class AbstractInputAdapter
{
public:
    virtual T input() const = 0;
};