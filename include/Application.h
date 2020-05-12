#pragma once

class AbstractBlackjack;

#include <map>
#include <string>
#include <vector>

#include "Player.h"
#include "PlayerNameInputValidator.h"
#include "PlayerStartCashInputValidator.h"
#include "AppAliases.h"

class Application
{
protected:
    AbstractBlackjack* game;

    AInputHandler inputHandler;

    ADisplayHandler displayHandler;

    std::map<std::string, ADisplayEntity*> displayEntityList;

    std::vector<Player> players;

public:
    Application(AInputHandler& inputHandler, ADisplayHandler& displayHandler)
            : inputHandler{inputHandler}, displayHandler{displayHandler}
    {
        this->inputHandler.assignApp(this);
    }

    void addMessageEntity(const std::string& key, ADisplayEntity* entity)
    {
        this->displayEntityList.insert(std::pair<std::string, ADisplayEntity*>(key, entity));
    }

    void displayMessage(std::string messageId) const
    {
        this->displayHandler.display(this->displayEntityList.at(messageId));
    }

    void displayMessages(std::vector<std::string> messageIds) const
    {
        std::vector<ADisplayEntity*> entities;

        for (auto const& messageId: messageIds)
        {
            entities.push_back(this->displayEntityList.at(messageId));
        }

        this->displayHandler.displayBatch(entities);
    }

    template <typename TType, typename TInputValidator>
    TType requestInput()
    {
        return this->inputHandler.template requestInput<TType, TInputValidator>();
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