#pragma once

class AbstractBlackjack;
//class TemplateInputValidator;

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

    void displayMessage(std::map<std::string, std::string> params) const
    {
        try
        {
            std::string messageId = params.at("id");

            this->displayHandler.display(this->displayEntityList.at(messageId), params);
        }
        catch (const std::out_of_range& e)
        {
            std::cout << "Application: message ID not found" << std::endl;
        }
    }

    void displayMessages(std::vector<std::map<std::string, std::string>> messageParamList) const
    {
        std::vector<ADisplayEntity*> entities;

        for (auto& params : messageParamList)
        {
            for (const auto& kv : params)
            {
                try
                {
                    std::string messageId = params.at("id");

                    entities.push_back(this->displayEntityList.at(messageId));
                }
                catch (const std::out_of_range& e)
                {
                    std::cout << "Application: message ID not found" << std::endl;
                }
            }
        }

        this->displayHandler.displayBatch(entities, messageParamList);
    }

    template <typename TType>
    TType requestInput(AbstractInputValidator* validator)
    {
        return this->inputHandler.template requestInput<TType>(validator);
    }

    void requestInputToCreatePlayer()
    {
//        std::string playerName = this->requestInput<std::string, PlayerNameInputValidator>();
//        u32 playerCash = this->requestInput<u32, PlayerStartCashInputValidator>();

        auto playerNameValidator = new PlayerNameInputValidator();
        auto playerStartCashValidator = new PlayerStartCashInputValidator();

        std::string playerName = this->requestInput<std::string>(playerNameValidator);
        u32 playerCash = this->requestInput<u32>(playerStartCashValidator);

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

    std::vector<Player>& getPlayers()
    {
        return this->players;
    }
};