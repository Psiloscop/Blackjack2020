#pragma once

#include <string>

#include "TemplateInputValidator.h"

class PlayerStartCashInputValidator: public TemplateInputValidator<u32>
{
public:
	bool validateValue(const u32& value) override
    {
        return value > 0 && value <= 1000;
    }

    u32 getValue() override
    {
	    return this->value;
    }

    std::vector<ADisplayMessageParam*> getErrorMessageParams() override
    {
        return {
            new ADisplayMessageParam("id", "mes_id_error_player_cash_invalid")
        };
    }

    std::vector<ADisplayMessageParam*> getRequestMessageParams() override
    {
        return {
            new ADisplayMessageParam("id", "mes_id_info_player_enter_start_cash")
        };
    }
};