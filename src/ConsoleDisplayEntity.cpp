#include "ConsoleDisplayEntity.h"

std::string& ConsoleDisplayEntity::getDisplayEntity()
{
    return this->entity;
}

bool ConsoleDisplayEntity::hasEndLine() const
{
    return this->endLine;
}
