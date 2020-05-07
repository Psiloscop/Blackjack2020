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
        return "Name is incorrect";
    }

	std::string getRequestMessageId() override
    {
        return "Please enter your nickname";
    }
};

#endif // __PLAYER_NAME_INPUT_VALIDATOR_H_INCLUDED__