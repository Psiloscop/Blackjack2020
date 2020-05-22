#pragma once

#include "TemplateInputValidator.h"
#include "Player.h"

class ActionInputValidator: public TemplateInputValidator<u8>
{
protected:
    u8 minNumber;

    u8 maxNumber;

public:
    ActionInputValidator(u8 minNumber, u8 maxNumber)
        : minNumber{minNumber}, maxNumber{maxNumber}
    {}

	bool validateValue(const u8& value) override
    {
        return value >= this->minNumber && value <= this->maxNumber;
    }

    u8 getValue() override
    {
        return this->value;
    }

    std::map<std::string, std::string> getErrorMessageParams() override
    {
        return {
            std::pair<std::string, std::string>("id", "mes_id_error_action_invalid_choice"),
            std::pair<std::string, std::string>("min", std::to_string(this->minNumber)),
            std::pair<std::string, std::string>("max", std::to_string(this->maxNumber))
        };
    }

    std::map<std::string, std::string> getRequestMessageParams() override
    {
        return {
            std::pair<std::string, std::string>("id", "mes_id_info_action_choose_action"),
            std::pair<std::string, std::string>("min", std::to_string(this->minNumber)),
            std::pair<std::string, std::string>("max", std::to_string(this->maxNumber))
        };
    }
};