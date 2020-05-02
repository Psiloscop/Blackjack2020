#ifndef __PLAYER_H_INCLUDED__
#define __PLAYER_H_INCLUDED__

class Application;
class AbstractInputValidator;

#include <string>

#include "Application.h"
#include "AppTypes.h"
#include "AbstractInputValidator.h"

class Player
{
private:
	Application* app;

	std::string name;

    u32 cash;

public:
    Player(Application* app, std::string name, u32 cash)
        : app{app}, name{name}, cash{cash}
    {}

	void increaseCash(u32 amount);

	void decreaseCash(u32 amount);

	template<typename T>
	T requestInput(const AbstractInputValidator& validator);
};

#endif // __PLAYER_H_INCLUDED__