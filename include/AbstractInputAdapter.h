#ifndef __ABSTRACT_INPUT_ADAPTER_H_INCLUDED__
#define __ABSTRACT_INPUT_ADAPTER_H_INCLUDED__

#include "BaseApplication.h"
#include "BaseInputAdapter.h"
#include "AbstractInputValidator.h"

template <typename T>
class AbstractInputAdapter: public BaseInputAdapter
{
public:
    virtual T input() const = 0;
};

#endif // __ABSTRACT_INPUT_ADAPTER_H_INCLUDED__