#ifndef __ABSTRACT_INPUT_VALIDATOR_H_INCLUDED__
#define __ABSTRACT_INPUT_VALIDATOR_H_INCLUDED__

#include <string>

#include "Application.h"

class AbstractInputValidator
{
private:
    Application* app;

public:
	template <typename T>
	bool validateValue(const T& value);

	virtual const std::string getErrorMessageId() = 0;

	virtual const std::string getRequestMessageId() = 0;
};

#endif // __ABSTRACT_INPUT_VALIDATOR_H_INCLUDED__