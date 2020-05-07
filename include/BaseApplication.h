#ifndef __BASE_APPLICATION_H_INCLUDED__
#define __BASE_APPLICATION_H_INCLUDED__

class AbstractBlackjack;

#include "AbstractBlackjack.h"

class BaseApplication
{
protected:
    AbstractBlackjack* game;

public:
    void displayMessage(std::string messageId) const;
    void displayMessages(std::string messageId[]) const;
};

#endif // __BASE_APPLICATION_H_INCLUDED__