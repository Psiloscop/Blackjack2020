#pragma once

#include <iostream>
#include <string>
#include <vector>

#include "AbstractDisplayHandler.h"
#include "ConsoleDisplayEntity.h"
#include "AppAliasDisplayMessageParam.h"

class ConsoleDisplayHandler: public AbstractDisplayHandler<ConsoleDisplayEntity>
{
protected:
    void clearConsole() const;

public:
    ConsoleDisplayHandler();

    void display(ConsoleDisplayEntity*, std::vector<ADisplayMessageParam*>) const override;
    void displayBatch(std::vector<ConsoleDisplayEntity*>, std::vector<std::vector<ADisplayMessageParam*>>) const override;

    void transformCardListEntity(ADisplayMessageParam*, std::vector<Card*>&) override;
};