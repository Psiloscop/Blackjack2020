#pragma once

#include "AbstractDisplayEntity.h"

class MockDisplayEntity: public AbstractDisplayEntity<std::string>
{
public:
    using AbstractDisplayEntity::AbstractDisplayEntity;
};