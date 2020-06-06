#pragma once

#include <utility>
#include <string>
#include <vector>

#include "AppAliasDisplayMessageParam.h"

class Card;

class DisplayMessageParamDealerCards: public ADisplayMessageParam
{
protected:
    std::vector<Card*>& cards;

public:
    DisplayMessageParamDealerCards(std::string key, std::string value, std::vector<Card*>& cards)
        : ADisplayMessageParam(std::move(key), std::move(value)), cards{cards}
    {}

    void transformValue(Application*) override;
};