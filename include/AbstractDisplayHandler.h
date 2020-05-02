#ifndef __ABSTRACT_DISPLAY_HANDLER_H_INCLUDED__
#define __ABSTRACT_DISPLAY_HANDLER_H_INCLUDED__

#include "AbstractDisplayEntity.h"

template <typename T>
class AbstractDisplayHandler
{
public:
	virtual void display(const AbstractDisplayEntity<T>& entity) const = 0;
};

#endif // __ABSTRACT_DISPLAY_HANDLER_H_INCLUDED__