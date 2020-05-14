#pragma once

#include <string>

#include "AppTypes.h"
#include "TemplateInputValidator.h"

class Application;

class Player
{
protected:
    Application* app;

	std::string name;

    u32 cash;

public:
    Player(Application* app, std::string name, u32 cash)
        : app{app}, name{name}, cash{cash}
    {}

	void increaseCash(u32 amount);

	void decreaseCash(u32 amount);

    std::string getName() const;

    u32 getCash() const;

    template <typename TType>
    TType requestInput(AbstractInputValidator*);
};