#ifndef __CONSOLE_INPUT_ADAPTER_H_INCLUDED__
#define __CONSOLE_INPUT_ADAPTER_H_INCLUDED__

#include <iostream>

#include "BaseApplication.h"
#include "AbstractInputAdapter.h"

template <typename T>
class ConsoleInputAdapter: public AbstractInputAdapter<T>
{
public:
    T input() const override
    {
        T value;

        std::cin >> value;

        return value;
    };
};

#endif // __CONSOLE_INPUT_ADAPTER_H_INCLUDED__