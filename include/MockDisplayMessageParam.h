#pragma once

#include <string>
#include <utility>

#include "TemplateDisplayMessageParam.h"

class MockDisplayMessageParam: public TemplateDisplayMessageParam<std::string, std::string>
{
public:
    using TemplateDisplayMessageParam::TemplateDisplayMessageParam;

    std::string getKey() const override
    {
        return this->key;
    }

    void setValue(std::string value) override
    {
        this->value = value;
    }

    std::string getValue() const override
    {
        return this->value;
    }

    void transformValue(Application* app) override
    {
    }
};