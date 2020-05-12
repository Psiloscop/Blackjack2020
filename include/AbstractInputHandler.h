#pragma once

#include <string>
#include <vector>

class Application;

template <template <class> typename TInputAdapter>
class AbstractInputHandler
{
protected:
    Application* app;

public:
    void assignApp(Application* app)
    {
        this->app = app;
    }

	template<typename TType, typename TInputValidator>
    TType requestInput() const
    {
        TType value;

        TInputAdapter<TType> adapter;
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