#pragma once

#include <vector>
#include <string>
#include <map>

#include "AbstractDisplayEntity.h"

template <typename T>
class AbstractDisplayHandler
{
protected:
    static char const leftBorder = '{', rightBorder = '}';

public:
    std::string processText(const std::string& text, const std::map<std::string, std::string>& params) const
    {
        unsigned int pos;
        std::string _text, _key;

//        for (const auto& [key, value] : params)
        for (const auto& kv : params)
        {
            _key = AbstractDisplayHandler::leftBorder + kv.first + AbstractDisplayHandler::rightBorder;
            _text = text;

            try
            {
                while((pos = _text.find(_key)) != std::string::npos)
                {
                    _text.replace(pos, _key.length(), kv.second);
                }
            }
            catch (const std::out_of_range& e)
            {}
        }

        return _text;
    }

	virtual void display(T*, std::map<std::string, std::string>) const = 0;
	virtual void displayBatch(std::vector<T*>, std::vector<std::map<std::string, std::string>>) const = 0;
};