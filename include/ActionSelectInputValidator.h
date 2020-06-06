#pragma once

#include <string>

#include "OptionInputValidator.h"
#include "DisplayMessageParamDealerCards.h"
#include "DisplayMessageParamPlayerCards.h"
#include "Card.h"

class ActionSelectInputValidator: public OptionInputValidator
{
public:
    ActionSelectInputValidator(u8 optionCount, std::string optionName, std::vector<std::string>& options,
                               std::vector<std::vector<Card*>>& playerCards, std::vector<Card*>& dealerCards)
        : OptionInputValidator(optionCount, optionName, options)
    {
        this->additionalMessageParams.insert(this->additionalMessageParams.begin(), {
            new ADisplayMessageParam("id", "mes_id_info_dealer_cards"),
            new DisplayMessageParamDealerCards("cards", "", dealerCards)
        });
        this->additionalMessageParams.insert(this->additionalMessageParams.begin() + 1, {
            new ADisplayMessageParam("id", "mes_id_info_player_cards"),
            new DisplayMessageParamPlayerCards("cards", "", playerCards)
        });
    }
};