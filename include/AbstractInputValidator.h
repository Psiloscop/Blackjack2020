#pragma once

#include <string>
#include <vector>
#include <map>

#include "AppTypes.h"

class AbstractInputValidator
{
protected:
    std::vector<std::map<std::string, std::string>> additionalMessageParams;

public:
	virtual std::map<std::string, std::string> getErrorMessageParams() = 0;

	virtual std::map<std::string, std::string> getRequestMessageParams() = 0;

	virtual std::vector<std::map<std::string, std::string>> getAdditionalMessageParams()
    {
	    return this->additionalMessageParams;
    }

    virtual void setAdditionalMessageParams(std::vector<std::map<std::string, std::string>> additionalMessageParams)
    {
        this->additionalMessageParams = additionalMessageParams;
    }
};