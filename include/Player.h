#ifndef __PLAYER_H_INCLUDED__
#define __PLAYER_H_INCLUDED__

//class BaseApplication;

#include "InputHandler.h"
#include "AbstractInputAdapter.h"
#include "AbstractDisplayHandler.h"
#include "AbstractDisplayEntity.h"

#include <string>

#include "Application.h"
//#include "BaseApplication.h"
#include "AppTypes.h"
#include "AbstractInputValidator.h"

//template <typename TInputHandler, template <class> typename TInputAdapter, typename TDisplayHandler, typename TDisplayEntity>
//class Application;
//using AApplication = Application<InputHandler, AbstractInputAdapter, AbstractDisplayHandler<void>, AbstractDisplayEntity<void>>;
//using AApplication = Application<InputHandler, ConsoleInputAdapter, ConsoleDisplayHandler, ConsoleDisplayEntity>;

class Player
{
private:
//    AApplication* app;
    BaseApplication* app;

	std::string name;

    u32 cash;

public:
    Player(BaseApplication* app, std::string name, u32 cash)
        : app{app}, name{name}, cash{cash}
    {}

	void increaseCash(u32 amount);

	void decreaseCash(u32 amount);

    std::string getName() const;

    u32 getCash() const;

    template <typename TType, typename TInputValidator>
    TType requestInput()
    {
        return this->app->requestInput<TType, TInputValidator>();
    }
};

#endif // __PLAYER_H_INCLUDED__