#ifndef __CONSOLE_DISPLAY_ENTITY_H_INCLUDED__
#define __CONSOLE_DISPLAY_ENTITY_H_INCLUDED__

#include <string>

#include "AbstractDisplayEntity.h"

class ConsoleDisplayEntity: public AbstractDisplayEntity<std::string>
{
public:
    explicit ConsoleDisplayEntity(std::string& value)
        : AbstractDisplayEntity(value)
    {}

    void setDisplayEntity(std::string&) const override;

    std::string& getDisplayEntity() const override;
};

#endif // __CONSOLE_DISPLAY_ENTITY_H_INCLUDED__