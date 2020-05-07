#ifndef __ABSTRACT_INPUT_VALIDATOR_H_INCLUDED__
#define __ABSTRACT_INPUT_VALIDATOR_H_INCLUDED__

#include <string>

#include "Application.h"

template <typename T>
class AbstractInputValidator
{
public:
	virtual bool validateValue(const T& value) = 0;

	virtual std::string getErrorMessageId() = 0;

	virtual std::string getRequestMessageId() = 0;
};

#endif // __ABSTRACT_INPUT_VALIDATOR_H_INCLUDED__