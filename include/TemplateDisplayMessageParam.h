#pragma once

#include <string>
#include <utility>

class Application;

template <typename TKey, typename TValue>
class TemplateDisplayMessageParam
{
protected:
    TKey key;

    TValue value;

    bool isValueTransformed = false;

public:
    TemplateDisplayMessageParam(TKey key, TValue value)
        : key{std::move(key)}, value{std::move(value)}
    {}

    virtual TKey getKey() const = 0;

    virtual void setValue(TValue) = 0;

    virtual TValue getValue() const = 0;

    virtual void transformValue(Application*) = 0;
};

