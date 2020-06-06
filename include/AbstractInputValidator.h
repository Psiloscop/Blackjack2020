#pragma once

#include <string>
#include <utility>
#include <vector>
#include <map>

#include "AppTypes.h"
#include "AppAliasDisplayMessageParam.h"

class AbstractInputValidator
{
protected:
    std::vector<std::vector<ADisplayMessageParam*>> additionalMessageParams;

public:
	virtual std::vector<ADisplayMessageParam*> getErrorMessageParams() = 0;

	virtual std::vector<ADisplayMessageParam*> getRequestMessageParams() = 0;

	virtual std::vector<std::vector<ADisplayMessageParam*>>& getAdditionalMessageParams()
    {
	    return this->additionalMessageParams;
    }

    virtual void setAdditionalMessageParams(std::vector<std::vector<ADisplayMessageParam*>> _additionalMessageParams)
    {
        this->additionalMessageParams = std::move(_additionalMessageParams);
    }
};