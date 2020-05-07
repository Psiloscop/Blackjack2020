#ifndef __ABSTRACT_DISPLAY_ENTITY_H_INCLUDED__
#define __ABSTRACT_DISPLAY_ENTITY_H_INCLUDED__

#include "BaseDisplayEntity.h"

template <typename T>
class AbstractDisplayEntity: public BaseDisplayEntity
{
protected:
    T entity;

public:
    AbstractDisplayEntity(T value)
        : entity(value) {}

	virtual T& getDisplayEntity() = 0;
};

#endif // __ABSTRACT_DISPLAY_ENTITY_H_INCLUDED__