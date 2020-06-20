#include "ConsoleDisplayEntity.h"

std::string& ConsoleDisplayEntity::getDisplayEntity()
{
    return this->entity;
}

void ConsoleDisplayEntity::setDisplayEntity(std::string value)
{
    this->entity = value;
}

bool ConsoleDisplayEntity::hasEndLine() const
{
    return this->endLine;
}

bool ConsoleDisplayEntity::pauseAfterDisplay() const
{
    return this->pause;
}