#pragma once

#include <string>

#include "OptionInputValidator.h"
#include "Card.h"

class ActionSelectInputValidator: public OptionInputValidator
{
protected:
    std::vector<Card*>& cards;

public:
    ActionSelectInputValidator(u8 optionCount, std::string optionName, std::vector<std::string>& options, std::vector<Card*>& cards)
        : OptionInputValidator(optionCount, optionName, options), cards{cards}
    {
//        std::vector<std::map<std::string, std::string>> messageParamList;
//        u8 number = 1;
//
//        for (auto& option : this->optionList)
//        {
//            messageParamList.push_back({
//                std::pair<std::string, std::string>("id", "mes_id_info_option_name"),
//                std::pair<std::string, std::string>("number", std::to_string(number++)),
//                std::pair<std::string, std::string>("option", option)
//            });
//        }
//
//        this->setAdditionalMessageParams(messageParamList);
    }

    std::map<std::string, std::string> getErrorMessageParams() override
    {
        return {
            std::pair<std::string, std::string>("id", "mes_id_error_invalid_choice"),
            std::pair<std::string, std::string>("optionName", this->optionName)
        };
    }

    std::map<std::string, std::string> getRequestMessageParams() override
    {
        return {
            std::pair<std::string, std::string>("id", "mes_id_info_choose_option"),
            std::pair<std::string, std::string>("min", std::to_string(1)),
            std::pair<std::string, std::string>("max", std::to_string(this->optionCount)),
            std::pair<std::string, std::string>("optionName", this->optionName)
        };
    }
};