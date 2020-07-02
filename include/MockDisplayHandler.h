#pragma once

#include "AbstractDisplayHandler.h"
#include "MockDisplayEntity.h"

class MockDisplayHandler: public AbstractDisplayHandler<MockDisplayEntity>
{
public:
    void display(MockDisplayEntity*, std::vector<ADisplayMessageParam*>) const override
    {}

    void displayBatch(std::vector<MockDisplayEntity*>, std::vector<std::vector<ADisplayMessageParam*>>) const override
    {}

    void transformCardListEntity(ADisplayMessageParam*, std::vector<Card*>&) override
    {}

    void transformCardListEntities(ADisplayMessageParam*, std::vector<std::vector<Card*>>&, u8 currentHand) override
    {}
};