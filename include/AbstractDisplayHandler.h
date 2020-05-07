#ifndef __ABSTRACT_DISPLAY_HANDLER_H_INCLUDED__
#define __ABSTRACT_DISPLAY_HANDLER_H_INCLUDED__

#include <vector>

#include "BaseDisplayHandler.h"
#include "AbstractDisplayEntity.h"

template <typename T>
class AbstractDisplayHandler: public BaseDisplayHandler
{
public:
	virtual void display(T*) const = 0;
	virtual void displayBatch(std::vector<T*>) const = 0;
};

#endif // __ABSTRACT_DISPLAY_HANDLER_H_INCLUDED__