#pragma once

#include <vector>
#include <string>
#include <map>

class Application;

template <template <class> typename TInputAdapter>
class TemplateInputHandler
{
protected:
    Application* app;

public:
    void assignApp(Application* app)
    {
        this->app = app;
    }

	template<typename TType>
    TType requestInput(AbstractInputValidator& validator) const
    {
        TType value;
        TInputAdapter<TType> adapter;
        auto& castedValidator = dynamic_cast<TemplateInputValidator<TType>&>(validator);

        auto errMesParams = castedValidator.getErrorMessageParams();
        auto reqMesParams = castedValidator.getRequestMessageParams();
        auto addMesParams = castedValidator.getAdditionalMessageParams();
        std::vector<std::map<std::string, std::string>> messageIds = {reqMesParams};

        if (addMesParams.size())
        {
            u8 insertionIndex = 0;

            for (auto& messageParams : addMesParams)
            {
                messageIds.insert(messageIds.begin() + insertionIndex++, messageParams);
            }

            this->app->displayMessages(messageIds);
        }
        else
        {
            this->app->displayMessage(reqMesParams);
        }

        value = adapter.input();

        messageIds.insert(messageIds.begin(), errMesParams);

        while (!castedValidator.validateValue(value))
        {
            this->app->displayMessages(messageIds);

            value = adapter.input();
        }

        return value;
    }
};