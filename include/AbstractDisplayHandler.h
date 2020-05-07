#ifndef __ABSTRACT_DISPLAY_HANDLER_H_INCLUDED__
#define __ABSTRACT_DISPLAY_HANDLER_H_INCLUDED__

#include "AbstractDisplayEntity.h"

class AbstractDisplayHandler
{
public:
    template <typename T>
	void display(const AbstractDisplayEntity<T>&);
};

#endif // __ABSTRACT_DISPLAY_HANDLER_H_INCLUDED__