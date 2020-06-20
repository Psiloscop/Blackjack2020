#pragma once

#include <string>
#include <utility>

#include "AbstractDisplayEntity.h"

class ConsoleDisplayEntity: public AbstractDisplayEntity<std::string>
{
protected:
    bool endLine;

    bool pause;

public:
    ConsoleDisplayEntity(std::string value, bool endLine = true, bool pause = false)
        : AbstractDisplayEntity(std::move(value)), endLine{endLine}, pause{pause}
    {}

    std::string& getDisplayEntity() override;

    void setDisplayEntity(std::string) override;

    bool hasEndLine() const;

    bool pauseAfterDisplay() const;
};