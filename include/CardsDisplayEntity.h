#pragma once

#include <vector>
#include <string>

#include "AppAliases.h"

class Card;

class CardsDisplayEntity: public ADisplayEntity
{
protected:
    std::vector<Card*> cards;

public:
    CardsDisplayEntity(std::string value)
        : ADisplayEntity(std::move(value))
    {}

    void setCardsToDisplay(ADisplayHandler& displayHandler, const std::vector<Card*> cards);
};