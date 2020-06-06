#pragma once

#include <string>
#include <utility>

#include "TemplateDisplayMessageParam.h"

class ConsoleDisplayMessageParam: public TemplateDisplayMessageParam<std::string, std::string>
{
public:
    ConsoleDisplayMessageParam(std::string key, std::string value)
        : TemplateDisplayMessageParam(std::move(key), std::move(value))
    {}

    std::string getKey() const override;

    void setValue(std::string) override;

    std::string getValue() const override;

    void transformValue(Application*) override;
};

