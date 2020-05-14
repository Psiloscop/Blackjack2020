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

    std::map<std::string, std::string> getErrorMessageParams() override
    {
        return {
            std::pair<std::string, std::string>("id", "mes_id_error_player_cash_invalid")
        };
    }

    std::map<std::string, std::string> getRequestMessageParams() override
    {
        return {
            std::pair<std::string, std::string>("id", "mes_id_info_player_enter_start_cash")
        };
    }
};