#ifndef __INT_DISPLAY_ENTITY_H_INCLUDED__
#define __INT_DISPLAY_ENTITY_H_INCLUDED__

#include <string>

#include "AbstractDisplayEntity.h"

class IntDisplayEntity: public AbstractDisplayEntity<int>
{
public:
    explicit IntDisplayEntity(int& value): AbstractDisplayEntity(value)
    {}

    void setDisplayEntity(int&) const override;

    int& getDisplayEntity() const override;
};

#endif // __INT_DISPLAY_ENTITY_H_INCLUDED__