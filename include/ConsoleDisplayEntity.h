#ifndef __CONSOLE_DISPLAY_ENTITY_H_INCLUDED__
#define __CONSOLE_DISPLAY_ENTITY_H_INCLUDED__

#include <string>
#include <utility>

#include "AbstractDisplayEntity.h"

class ConsoleDisplayEntity: public AbstractDisplayEntity<std::string>
{
protected:
    bool endLine;

public:
    ConsoleDisplayEntity(std::string value, bool endLine = true)
        : AbstractDisplayEntity(std::move(value)), endLine{endLine}
    {}

    std::string& getDisplayEntity() override;

    bool hasEndLine() const;
};

#endif // __CONSOLE_DISPLAY_ENTITY_H_INCLUDED__