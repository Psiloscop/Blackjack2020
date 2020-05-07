#ifndef __INPUT_HANDLER_H_INCLUDED__
#define __INPUT_HANDLER_H_INCLUDED__

class Application;

#include "Application.h"
#include "AbstractInputAdapter.h"
#include "AbstractInputValidator.h"

#include "PlayerNameInputValidator.h"

class InputHandler
{
protected:
    Application* app;

public:
    void assignApp(Application*);

	template<typename Type, template <class> typename TAbstractInputAdapter, template <class> typename TAbstractInputValidator>
    Type requestInput() const
    {
        Type value, prevVal = "";

        auto* adapter = new TAbstractInputAdapter<Type>;
        auto* validator = new TAbstractInputValidator<Type>;

        std::string errMesId = validator->getErrorMessageId();
        std::string reqMesId = validator->getRequestMessageId();
        std::string messages[] = {errMesId, reqMesId};

        this->app->displayMessage(reqMesId);

        value = adapter->input();

        while (!validator->validateValue(value))
        {
            value != prevVal
                ? this->app->displayMessages(messages)
                : this->app->displayMessage(reqMesId);

            prevVal = value;

            value = adapter->input();
        }

        return value;
    }
};

#endif // __INPUT_HANDLER_H_INCLUDED__