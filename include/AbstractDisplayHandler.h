#ifndef __ABSTRACT_DISPLAY_HANDLER_H_INCLUDED__
#define __ABSTRACT_DISPLAY_HANDLER_H_INCLUDED__

#include "AbstractDisplayEntity.h"

class AbstractDisplayHandler
{
public:
	virtual const void display(const AbstractDisplayEntity& entity) = 0;
};

#endif // __ABSTRACT_DISPLAY_HANDLER_H_INCLUDED__