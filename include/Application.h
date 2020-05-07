#ifndef __APPLICATION_H_INCLUDED__
#define __APPLICATION_H_INCLUDED__

class AbstractBlackjack;

#include "AbstractBlackjack.h"

class Application
{
protected:
    AbstractBlackjack* game;

public:
    void displayMessage(std::string messageId) const;
    void displayMessages(std::string messageId[]) const;
};

#endif // __APPLICATION_H_INCLUDED__