#include "intDisplayEntity.h"

void IntDisplayEntity::setDisplayEntity(int& value) const
{
    this->entity = value;
}

int& IntDisplayEntity::getDisplayEntity() const
{
    return this->entity;
}