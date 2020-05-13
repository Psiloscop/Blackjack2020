#pragma once

#include "AbstractInputAdapter.h"

template <typename T>
class MockInputAdapter: public AbstractInputAdapter<T>
{
public:
    T input() const override
    {};
};