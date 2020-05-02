#ifndef __CONSOLE_INPUT_ADAPTER_H_INCLUDED__
#define __CONSOLE_INPUT_ADAPTER_H_INCLUDED__

#include <iostream>

#include "Application.h"
#include "AbstractInputAdapter.h"

template <typename T>
class ConsoleInputAdapter: public AbstractInputAdapter<T>
{
    T input() const override;
};

#endif // __CONSOLE_INPUT_ADAPTER_H_INCLUDED__