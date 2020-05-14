#pragma once

#include <iostream>
#include <string>

#include "AbstractDisplayHandler.h"
#include "ConsoleDisplayEntity.h"

class ConsoleDisplayHandler: public AbstractDisplayHandler<ConsoleDisplayEntity>
{
protected:
    void clearConsole() const;

public:
    void display(ConsoleDisplayEntity*, std::map<std::string, std::string>) const override;
    void displayBatch(std::vector<ConsoleDisplayEntity*>, std::vector<std::map<std::string, std::string>>) const override;
};