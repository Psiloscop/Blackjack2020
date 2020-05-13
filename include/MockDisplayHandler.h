#pragma once

#include "AbstractDisplayHandler.h"
#include "MockDisplayEntity.h"

class MockDisplayHandler: public AbstractDisplayHandler<MockDisplayEntity>
{
public:
    void display(MockDisplayEntity*) const override
    {}

    void displayBatch(std::vector<MockDisplayEntity*>) const override
    {}
};