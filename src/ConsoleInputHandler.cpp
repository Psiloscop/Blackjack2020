#include "ConsoleInputHandler.h"

template <typename T>
T AbstractInputHandler::requestInput(AbstractInputValidator &validator)
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

        std::cin >> value;
    }

    return value;
}