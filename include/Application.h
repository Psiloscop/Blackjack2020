#ifndef __APPLICATION_H_INCLUDED__
#define __APPLICATION_H_INCLUDED__

//class Player;
class AbstractBlackjack;

#include <map>
#include <string>
#include <vector>

#include "AbstractBlackjack.h"
#include "BaseApplication.h"
#include "BaseDisplayHandler.h"
#include "BaseDisplayEntity.h"
#include "AbstractDisplayHandler.h"
#include "AbstractDisplayEntity.h"
#include "AbstractInputAdapter.h"
#include "ConsoleDisplayHandler.h"
#include "PlayerNameInputValidator.h"
#include "PlayerStartCashInputValidator.h"
#include "InputHandler.h"

template <typename TInputHandler, template <class> typename TInputAdapter, typename TDisplayHandler, typename TDisplayEntity>
class Application
        : public BaseApplication
{
protected:
    AbstractBlackjack* game;

    TInputHandler inputHandler;

    TDisplayHandler displayHandler;

	std::map<std::string, TDisplayEntity*> displayEntityList;

    std::vector<Player> players;

public:
    Application()
    : BaseApplication()
    {
        // Compile-time check for template types
        static_assert(std::is_base_of<InputHandler, TInputHandler>::value,
                "Type parameter of this class must be InputHandler");
        static_assert(std::is_base_of<BaseInputAdapter, TInputAdapter<void>>::value,
                "Type parameter of this class must derive from AbstractInputAdapter");
        static_assert(std::is_base_of<BaseDisplayHandler, TDisplayHandler>::value,
                "Type parameter of this class must derive from AbstractDisplayHandler");
        static_assert(std::is_base_of<BaseDisplayEntity, TDisplayEntity>::value,
                      "Type parameter of this class must derive from AbstractDisplayEntity");

        this->inputHandler.assignApp(this);
    }

    void addMessageEntity(const std::string& key, TDisplayEntity* entity)
    {
        this->displayEntityList.insert(std::pair<std::string, TDisplayEntity*>(key, entity));
    }

    void displayMessage(std::string messageId) const
    {
        this->displayHandler.display(this->displayEntityList.at(messageId));
    }

    void displayMessages(std::vector<std::string> messageIds) const
    {
        std::vector<TDisplayEntity*> entities;

        for (auto const& messageId: messageIds)
        {
            entities.push_back(this->displayEntityList.at(messageId));
        }

        this->displayHandler.displayBatch(entities);
    }
    
    template <typename TType, typename TInputValidator>
    TType requestInput()
    {
        return this->inputHandler.template requestInput<TType, TInputAdapter, TInputValidator>();
    }

    void requestInputToCreatePlayer()
    {
        std::string playerName = this->requestInput<std::string, PlayerNameInputValidator>();
        u32 playerCash = this->requestInput<u32, PlayerStartCashInputValidator>();

        this->createPlayer(playerName, playerCash);
    }

    void createPlayer(const std::string& playerName, u32 playerCash)
    {
        Player player(this, playerName, playerCash);

        this->players.push_back(std::move(player));
    }

    Player& getPlayer(u8 index)
    {
        if (index >= this->players.size())
        {
            throw std::out_of_range("Application::getPlayer(index) - index is out of range");
        }

        return this->players[index];
    }
};

//#include "Application.h"
//#include "InputHandler.h"
//#include "ConsoleInputAdapter.h"
//#include "ConsoleDisplayHandler.h"
//#include "ConsoleDisplayEntity.h"
//
//using TApplication = Application<InputHandler, ConsoleInputAdapter, ConsoleDisplayHandler, ConsoleDisplayEntity>;

#endif // __APPLICATION_H_INCLUDED__