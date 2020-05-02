#ifndef __ABSTRACT_INPUT_ADAPTER_H_INCLUDED__
#define __ABSTRACT_INPUT_ADAPTER_H_INCLUDED__

#include "Application.h"
#include "AbstractInputValidator.h"

template <typename T>
class AbstractInputAdapter
{
public:
    virtual T input() const = 0;
};

#endif // __ABSTRACT_INPUT_ADAPTER_H_INCLUDED__