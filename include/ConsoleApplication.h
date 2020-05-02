#ifndef __CONSOLE_APPLICATION_H_INCLUDED__
#define __CONSOLE_APPLICATION_H_INCLUDED__

#include <map>
#include <string>

#include "Application.h"
#include "ConsoleDisplayHandler.h"

template <typename T>
class ConsoleApplication: public Application
{
private:
	AbstractBlackjack* game;

	AbstractInputHandler* inputHandler;

	AbstractDisplayHandler<T>* displayHandler;

	std::map<std::string, AbstractDisplayEntity<T>*> displayEntityList;

public:
    ConsoleApplication(AbstractDisplayHandler<T>* displayHandler)
        : displayHandler(displayHandler)
    {

    }
};

#endif // __CONSOLE_APPLICATION_H_INCLUDED__