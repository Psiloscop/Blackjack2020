#ifndef __PLAYER_NAME_INPUT_VALIDATOR_H_INCLUDED__
#define __PLAYER_NAME_INPUT_VALIDATOR_H_INCLUDED__

#include <string>

#include "AbstractInputValidator.h"

template <typename T>
class PlayerNameInputValidator: public AbstractInputValidator<T>
{
public:
	bool validateValue(const T& value) override
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

#endif // __PLAYER_NAME_INPUT_VALIDATOR_H_INCLUDED__