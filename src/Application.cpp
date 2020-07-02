#include "Application.h"

Application::Application(AbstractBlackjack& game, AInputHandler& inputHandler, ADisplayHandler& displayHandler)
: game{game}, inputHandler{inputHandler}, displayHandler{displayHandler}
{
    this->game.assignApp(this);
    this->inputHandler.assignApp(this);
}

ADisplayHandler& Application::getDisplayHandler()
{
    return this->displayHandler;
}

void Application::addMessageEntity(const std::string& key, ADisplayEntity* entity)
{
    this->displayEntityList.insert(std::pair<std::string, ADisplayEntity*>(key, entity));
}

void Application::displayMessage(std::vector<ADisplayMessageParam*> params) const
{
    auto* app = const_cast<Application*>(this);

    std::string messageId;

    for (auto& kv : params)
    {
        try
        {
            if (kv->getKey() == "id")
            {
                messageId = kv->getValue();
            }
            else
            {
                kv->transformValue(app);
            }
        }
        catch (const std::out_of_range& e)
        {
            std::cout << "Application: message ID not found" << std::endl;
        }
    }

    if (!messageId.empty())
    {
        this->displayHandler.display(this->displayEntityList.at(messageId), params);
    }
    else
    {
        throw std::out_of_range("Application: message ID not found");
    }
}

void Application::displayMessages(std::vector<std::vector<ADisplayMessageParam*>> messageParamList) const
{
    auto* app = const_cast<Application*>(this);

    std::vector<ADisplayEntity*> entities;

    for (auto& params : messageParamList)
    {
        for (auto& kv : params)
        {
            try
            {
                if (kv->getKey() == "id")
                {
                    entities.push_back(this->displayEntityList.at(kv->getValue()));
                }
                else
                {
                    kv->transformValue(app);
                }
            }
            catch (const std::out_of_range& e)
            {
                std::cout << "Application: message ID not found" << std::endl;
            }
        }
    }

    this->displayHandler.displayBatch(entities, messageParamList);
}

void Application::requestInputToCreatePlayer()
{
    PlayerNameInputValidator playerNameValidator;
    PlayerStartCashInputValidator playerStartCashValidator;

    std::string playerName = this->requestInput<std::string>(playerNameValidator);
    u32 playerCash = this->requestInput<u32>(playerStartCashValidator);

    this->createPlayer(playerName, playerCash);
}

void Application::createPlayer(const std::string& playerName, u32 playerCash)
{
    Player player(this, playerName, playerCash);

    this->players.push_back(player);
}

Player& Application::getPlayer(u8 index)
{
    if (index >= this->players.size())
    {
        throw std::out_of_range("Application::getPlayer(index) - index is out of range");
    }

    return this->players[index];
}

std::vector<Player>& Application::getPlayers()
{
    return this->players;
}

void Application::startGame()
{
    this->game.prepareGame();
    this->game.playGame();
    this->game.finishGame();
}