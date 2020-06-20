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
                               Box& dealerBox, Box& playerBox, bool hideSecondDealerCard = true)
        : OptionInputValidator(optionCount, optionName, options)
    {
        this->additionalMessageParams.insert(this->additionalMessageParams.begin(), {
            new ADisplayMessageParam("id", "mes_id_info_dealer_cards"),
            new DisplayMessageParamDealerCards("cards", "", dealerBox.getHandCards(), hideSecondDealerCard)
        });
        this->additionalMessageParams.insert(this->additionalMessageParams.begin() + 1, {
            new ADisplayMessageParam("id", "mes_id_info_player_cards"),
            new ADisplayMessageParam("name", playerBox.getPlayer().getName()),
            new DisplayMessageParamPlayerCards("cards", "", playerBox.getAllCards(), playerBox.getCurrentHandNumber())
        });
    }
};