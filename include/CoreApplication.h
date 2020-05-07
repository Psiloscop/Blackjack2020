#ifndef __CORE_APPLICATION_H_INCLUDED__
#define __CORE_APPLICATION_H_INCLUDED__

class Player;

#include <map>
#include <string>
#include <vector>

#include "Application.h"
#include "AbstractDisplayHandler.h"
#include "AbstractDisplayEntity.h"
#include "AbstractInputAdapter.h"
#include "ConsoleDisplayHandler.h"
#include "PlayerNameInputValidator.h"
#include "InputHandler.h"

template <typename InputHandler, template <class> typename TAbstractInputAdapter, typename TAbstractDisplayHandler, typename TDisplayEntity>
class CoreApplication: public Application
{
protected:
    InputHandler inputHandler;

    TAbstractDisplayHandler displayHandler;

	std::map<std::string, AbstractDisplayEntity<TDisplayEntity>*> displayEntityList;

    std::vector<Player*> players;

public:
    CoreApplication(): Application()
    {
        // Compile-time check
//        static_assert(std::is_base_of<AbstractInputAdapter, TAbstractInputAdapter>::value,
//                "Type parameter of this class must derive from AbstractInputAdapter");
        static_assert(std::is_base_of<AbstractDisplayHandler, TAbstractDisplayHandler>::value,
                "Type parameter of this class must derive from AbstractDisplayHandler");

        this->inputHandler.assignApp(this);
    }

    void createPlayer()
    {
        std::string playerName = this->inputHandler
                .template requestInput<std::string, TAbstractInputAdapter, PlayerNameInputValidator>();

        std::cout << playerName;
    }
};

#endif // __CORE_APPLICATION_H_INCLUDED__