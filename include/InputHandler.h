#ifndef __INPUT_HANDLER_H_INCLUDED__
#define __INPUT_HANDLER_H_INCLUDED__

class BaseApplication;

#include <iostream>

#include "BaseApplication.h"
#include "AbstractInputAdapter.h"
#include "AbstractInputValidator.h"

#include "PlayerNameInputValidator.h"

class InputHandler
{
protected:
    BaseApplication* app;

public:
    void assignApp(BaseApplication*);

	template<typename Type, template <class> typename TInputAdapter, typename TInputValidator>
    Type requestInput() const
    {
        Type value;

        TInputAdapter<Type> adapter;
        TInputValidator validator;

        std::string errMesId = validator.getErrorMessageId();
        std::string reqMesId = validator.getRequestMessageId();
        std::vector<std::string> messageIds = {errMesId, reqMesId};

        this->app->displayMessage(reqMesId);

        value = adapter.input();

        while (!validator.validateValue(value))
        {
            this->app->displayMessages(messageIds);

            value = adapter.input();
        }

        return value;
    }
};

#endif // __INPUT_HANDLER_H_INCLUDED__