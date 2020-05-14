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

    std::map<std::string, std::string> getErrorMessageParams() override
    {
//        std::map<std::string, std::string> params = {
//                std::pair<std::string, std::string>("id", "mes_id_error_player_name_invalid")
//        };

        return {
            std::pair<std::string, std::string>("id", "mes_id_error_player_name_invalid")
        };
    }

    std::map<std::string, std::string> getRequestMessageParams() override
    {
        return {
                std::pair<std::string, std::string>("id", "mes_id_info_player_enter_name")
        };
    }
};