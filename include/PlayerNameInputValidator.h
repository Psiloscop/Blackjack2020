#pragma once

#include <string>

#include "TemplateInputValidator.h"

class PlayerNameInputValidator: public TemplateInputValidator<std::string>
{
public:
	bool validateValue(const std::string& value) override
    {
        return true;
    }

    std::string getValue() override
    {
        return this->value;
    }

    std::vector<ADisplayMessageParam*> getErrorMessageParams() override
    {
        return {
            new ADisplayMessageParam("id", "mes_id_error_player_name_invalid")
        };
    }

    std::vector<ADisplayMessageParam*> getRequestMessageParams() override
    {
        return {
            new ADisplayMessageParam("id", "mes_id_info_player_enter_name")
        };
    }
};