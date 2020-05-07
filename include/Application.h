#ifndef __APPLICATION_H_INCLUDED__
#define __APPLICATION_H_INCLUDED__

class Player;

#include <map>
#include <string>
#include <vector>

#include "BaseApplication.h"
#include "BaseDisplayHandler.h"
#include "AbstractDisplayHandler.h"
#include "AbstractDisplayEntity.h"
#include "AbstractInputAdapter.h"
#include "ConsoleDisplayHandler.h"
#include "PlayerNameInputValidator.h"
#include "InputHandler.h"

template <typename TInputHandler, template <class> typename TAbstractInputAdapter, typename TDisplayHandler, typename TDisplayEntity>
class Application: public BaseApplication
{
protected:
    TInputHandler inputHandler;

    TDisplayHandler displayHandler;

	std::map<std::string, AbstractDisplayEntity<TDisplayEntity>*> displayEntityList;

    std::vector<Player*> players;

public:
    Application(): BaseApplication()
    {
        // Compile-time check
        static_assert(std::is_base_of<InputHandler, TInputHandler>::value,
                "Type parameter of this class must be InputHandler");
        static_assert(std::is_base_of<BaseInputAdapter, TAbstractInputAdapter<void>>::value,
                "Type parameter of this class must derive from AbstractInputAdapter");
        static_assert(std::is_base_of<BaseDisplayHandler, TDisplayHandler>::value,
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

#endif // __APPLICATION_H_INCLUDED__