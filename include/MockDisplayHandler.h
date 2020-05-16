#pragma once

#include "AbstractDisplayHandler.h"
#include "MockDisplayEntity.h"

class MockDisplayHandler: public AbstractDisplayHandler<MockDisplayEntity>
{
public:
    void display(MockDisplayEntity*, std::map<std::string, std::string>) const override
    {}

    void displayBatch(std::vector<MockDisplayEntity*>, std::vector<std::map<std::string, std::string>>) const override
    {}
};