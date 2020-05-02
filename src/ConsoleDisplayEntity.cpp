#include "ConsoleDisplayEntity.h"

void ConsoleDisplayEntity::setDisplayEntity(std::string& value) const
{
    this->entity = value;
}

std::string& ConsoleDisplayEntity::getDisplayEntity() const
{
    return this->entity;
}