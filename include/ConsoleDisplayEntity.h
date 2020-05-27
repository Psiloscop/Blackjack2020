#pragma once

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

    void setDisplayEntity(std::string) override;

    bool hasEndLine() const;
};