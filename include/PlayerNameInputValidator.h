#pragma once

#include <string>

#include "AbstractInputValidator.h"

class PlayerNameInputValidator: public AbstractInputValidator<std::string>
{
public:
	bool validateValue(const std::string& value) override
    {
        return true;
    }

	std::string getErrorMessageId() override
    {
        return "mes_id_error_player_name_invalid";
    }

	std::string getRequestMessageId() override
    {
        return "mes_id_info_player_enter_name";
    }
};