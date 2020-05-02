#ifndef __INPUT_HANDLER_H_INCLUDED__
#define __INPUT_HANDLER_H_INCLUDED__

#include "Application.h"
#include "AbstractInputAdapter.h"
#include "AbstractInputValidator.h"

class InputHandler
{
private:
    Application* app;

public:
	template<typename T>
	T requestInput(AbstractInputAdapter<T>& adapter, AbstractInputValidator& validator) const;
};

#endif // __INPUT_HANDLER_H_INCLUDED__