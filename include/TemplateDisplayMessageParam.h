#pragma once

#include <string>
#include <utility>

class Application;

template <typename TKey, typename TValue>
class TemplateDisplayMessageParam
{
protected:
    std::string key;

    std::string value;

    bool isValueTransformed = false;

public:
    TemplateDisplayMessageParam(std::string key, std::string value)
        : key{std::move(key)}, value{std::move(value)}
    {}

    virtual TKey getKey() const = 0;

    virtual void setValue(TValue) = 0;

    virtual TValue getValue() const = 0;

    virtual void transformValue(Application*) = 0;
};

