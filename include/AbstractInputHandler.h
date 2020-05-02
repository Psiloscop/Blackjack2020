#ifndef __ABSTRACT_INPUT_HANDLER_H_INCLUDED__
#define __ABSTRACT_INPUT_HANDLER_H_INCLUDED__

#include "Application.h"
#include "AbstractInputValidator.h"

class AbstractInputHandler
{
private:
    Application* app;

public:
	template<typename T>
	T requestInput(AbstractInputValidator& validator);
};

#endif // __ABSTRACT_INPUT_HANDLER_H_INCLUDED__