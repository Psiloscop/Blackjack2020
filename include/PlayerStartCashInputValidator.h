#ifndef __PLAYER_START_CASH_INPUT_VALIDATOR_H_INCLUDED__
#define __PLAYER_START_CASH_INPUT_VALIDATOR_H_INCLUDED__

#include <string>

#include "AbstractInputValidator.h"

class PlayerStartCashInputValidator: public AbstractInputValidator<u32>
{
public:
	bool validateValue(const u32& value) override
    {
        return value > 0 && value <= 1000;
    }

	std::string getErrorMessageId() override
    {
        return "mes_id_error_player_cash_invalid";
    }

	std::string getRequestMessageId() override
    {
        return "mes_id_info_player_enter_start_cash";
    }
};

#endif // __PLAYER_START_CASH_INPUT_VALIDATOR_H_INCLUDED__