#include "ConsoleInputAdapter.h"

template <typename T>
T ConsoleInputAdapter<T>::input() const
{
    T value = NULL;

    std::cin >> value;

    return value;
}