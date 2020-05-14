#pragma once

class AbstractBlackjack;
//class TemplateInputValidator;

#include <map>
#include <string>
#include <utility>
#include <vector>

#include "AbstractBlackjack.h"
#include "Player.h"
#include "PlayerNameInputValidator.h"
#include "PlayerStartCashInputValidator.h"

#include "AppAliases.h"

class Application
{
public:
    AbstractBlackjack& game; // Temporary

protected:
//    AbstractBlackjack& game;

    AInputHandler inputHandler;

    ADisplayHandler displayHandler;

    std::map<std::string, ADisplayEntity*> displayEntityList;

    std::vector<Player> players;

public:
    Application(AbstractBlackjack& game, AInputHandler& inputHandler, ADisplayHandler& displayHandler);

    void addMessageEntity(const std::string& key, ADisplayEntity* entity);

    void displayMessage(std::map<std::string, std::string> params) const;

    void displayMessages(std::vector<std::map<std::string, std::string>> messageParamList) const;

    template <typename TType>
    TType requestInput(AbstractInputValidator& validator)
    {
        return this->inputHandler.template requestInput<TType>(validator);
    }

    void requestInputToCreatePlayer();

    void createPlayer(const std::string& playerName, u32 playerCash);

    Player& getPlayer(u8 index);

    std::vector<Player>& getPlayers();
};