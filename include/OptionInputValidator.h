#pragma once

#include <string>

#include "TemplateInputValidator.h"
#include "Player.h"

class OptionInputValidator: public TemplateInputValidator<u8>
{
protected:
    u8 optionCount;

    std::string optionName;

    std::vector<std::string>& options;

public:
    OptionInputValidator(u8 optionCount, std::string optionName, std::vector<std::string>& options)
        : optionCount{optionCount}, optionName{optionName}, options{options}
    {
        std::vector<std::vector<ADisplayMessageParam*>> messageParamList;
        u8 number = 1;

        for (auto& option : this->options)
        {
            messageParamList.push_back({
                new ADisplayMessageParam("id", "mes_id_info_option_name"),
                new ADisplayMessageParam("number", std::to_string(number++)),
                new ADisplayMessageParam("option", option)
            });
        }

        this->setAdditionalMessageParams(messageParamList);
    }

	bool validateValue(const u8& value) override
    {
        return value >= 1 && value <= this->optionCount;
    }

    u8 getValue() override
    {
        return this->value;
    }

    std::vector<ADisplayMessageParam*> getErrorMessageParams() override
    {
        return {
            new ADisplayMessageParam("id", "mes_id_error_invalid_choice"),
            new ADisplayMessageParam("optionName", this->optionName)
        };
    }

    std::vector<ADisplayMessageParam*> getRequestMessageParams() override
    {
        return {
            new ADisplayMessageParam("id", "mes_id_info_choose_option"),
            new ADisplayMessageParam("min", std::to_string(1)),
            new ADisplayMessageParam("max", std::to_string(this->optionCount)),
            new ADisplayMessageParam("optionName", this->optionName)
        };
    }
};