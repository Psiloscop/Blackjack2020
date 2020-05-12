#pragma once

#include <iostream>
#include <algorithm>

#include "AbstractInputAdapter.h"

template <typename T>
class ConsoleInputAdapter: public AbstractInputAdapter<T>
{
public:
    T input() const override
    {
        T value;

        std::cin >> value;

        if (std::cin.fail())
        {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }

        return value;
    };
};