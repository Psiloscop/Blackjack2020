#include "InputHandler.h"

template <typename T>
T InputHandler::requestInput(AbstractInputAdapter<T>& adapter, AbstractInputValidator& validator) const
{
    T value = NULL;

    std::string errMesId = validator.getErrorMessageId();
    std::string reqMesId = validator.getRequestMessageId();
    std::string messages[] = {errMesId, reqMesId};

    while (!validator.validateValue(value))
    {
        value != NULL
            ? this->app->displayMessages(messages)
            : this->app->displayMessage(reqMesId);

        value = adapter.input();
    }

    return value;
}