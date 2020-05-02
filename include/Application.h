#ifndef __APPLICATION_H_INCLUDED__
#define __APPLICATION_H_INCLUDED__

class AbstractBlackjack;
class AbstractInputHandler;

#include <map>
#include <string>

#include "AbstractBlackjack.h"
#include "AbstractDisplayHandler.h"
#include "AbstractDisplayEntity.h"
#include "AbstractInputHandler.h"

class Application
{
private:
	AbstractBlackjack* game;

	AbstractInputHandler* inputHandler;

	AbstractDisplayHandler* displayHandler;

	std::map<std::string, AbstractDisplayEntity*> displayEntityList;

public:
    void displayMessage(std::string messageId) const;
    void displayMessages(std::string messageId[]) const;
};

#endif // __APPLICATION_H_INCLUDED__