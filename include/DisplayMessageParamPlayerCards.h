#pragma once

#include <utility>
#include <string>
#include <vector>

#include "AppAliasDisplayMessageParam.h"

class Card;

class DisplayMessageParamPlayerCards: public ADisplayMessageParam
{
protected:
    std::vector<std::vector<Card*>> cards;

public:
    DisplayMessageParamPlayerCards(std::string key, std::string value, std::vector<std::vector<Card*>>& cards)
        : ADisplayMessageParam(std::move(key), std::move(value)), cards{cards}
    {}

    void transformValue(Application*) override;
};