#pragma once

#include <vector>
#include <string>
#include <map>

#include "AbstractDisplayEntity.h"
#include "AppAliasDisplayMessageParam.h"
#include "Card.h"

template <typename T>
class AbstractDisplayHandler
{
protected:
    static char const strLB = '{', strRB = '}';
//    static char const arrLB = '[', arrRB = ']';

//    std::map<std::string, u16> arrLastIndexes = {};

public:
    std::string processText(const std::string& text, const std::vector<ADisplayMessageParam*>& params) const
    {
        unsigned int pos;
        std::string _text = text, _strKey, _arrKey;

        // Searching for string vars
        for (const auto& kv : params)
        {
            _strKey = AbstractDisplayHandler::strLB + kv->getKey() + AbstractDisplayHandler::strRB;

            if (kv->getKey() == "id")
            {
                continue;
            }

            try
            {
                while ((pos = _text.find(_strKey)) != std::string::npos)
                {
                    _text = _text.replace(pos, _strKey.length(), kv->getValue());
                }
            }
            catch (const std::out_of_range& e)
            {}
        }

        // Searching for array vars
//        for (const auto& kv : params)
//        {
//            _arrKey = AbstractDisplayHandler::arrLB + kv.first + AbstractDisplayHandler::arrRB;
//
//            if (kv.first == "id")
//            {
//                continue;
//            }
//
//            try
//            {
//                if ((pos = _text.find(_arrKey)) != std::string::npos)
//                {
//                    _text = _text.replace(pos, _arrKey.length(), kv.second);
//
//                    this->arrLastIndexes.insert(std::pair<std::string, u16>(_arrKey, pos + _arrKey.length()));
//                }
//                else
//                {
//                    pos = this->arrLastIndexes.at(_arrKey)->second;
//
//                    _text = _text.insert(pos, " " + kv.second);
//
//                    this->arrLastIndexes.insert(std::pair<std::string, u16>(_arrKey, pos + kv.second.length() + 1));
//                }
//            }
//            catch (const std::out_of_range& e)
//            {}
//        }

        return _text;
    }

	virtual void display(T*, std::vector<ADisplayMessageParam*>) const = 0;
    virtual void displayBatch(std::vector<T*>, std::vector<std::vector<ADisplayMessageParam*>>) const = 0;

    virtual void transformCardListEntity(ADisplayMessageParam*, std::vector<Card*>&) = 0;
    virtual void transformCardListEntities(ADisplayMessageParam*, std::vector<std::vector<Card*>>&, u8 currentHand) = 0;
};