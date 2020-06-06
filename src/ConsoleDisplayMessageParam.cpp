#include "ConsoleDisplayMessageParam.h"
#include "Application.h"

std::string ConsoleDisplayMessageParam::getKey() const
{
    return this->key;
}

void ConsoleDisplayMessageParam::setValue(std::string value)
{
    this->value = value;
}

std::string ConsoleDisplayMessageParam::getValue() const
{
    return this->value;
}

void ConsoleDisplayMessageParam::transformValue(Application* app)
{
}