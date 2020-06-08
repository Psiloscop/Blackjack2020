#pragma once

#include <utility>
#include <string>
#include <vector>

#include "AppAliasDisplayMessageParam.h"
#include "AppTypes.h"

class Card;

class DisplayMessageParamPlayerCards: public ADisplayMessageParam
{
protected:
    std::vector<std::vector<Card*>> cards;

    u8 currentHand;

public:
    DisplayMessageParamPlayerCards(std::string key, std::string value, std::vector<std::vector<Card*>>& cards, u8 currentHand)
        : ADisplayMessageParam(std::move(key), std::move(value)), cards{cards}, currentHand{currentHand}
    {}

    void transformValue(Application*) override;
};