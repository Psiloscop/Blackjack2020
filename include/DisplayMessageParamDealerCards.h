#pragma once

#include <utility>
#include <string>
#include <vector>

#include "AppAliasDisplayMessageParam.h"
#include "CardHidden.h"

class Card;

class DisplayMessageParamDealerCards: public ADisplayMessageParam
{
protected:
    std::vector<Card*> cards;

    CardHidden hiddenCard;

    bool hideSecondDealerCard;

public:
    DisplayMessageParamDealerCards(std::string key, std::string value, std::vector<Card*>& cards, bool hideSecondDealerCard)
        : ADisplayMessageParam(std::move(key), std::move(value)), cards{cards}, hideSecondDealerCard{hideSecondDealerCard}
    {}

    void transformValue(Application*) override;
};