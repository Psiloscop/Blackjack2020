#include "Application.h"
#include "AppTypes.h"
#include "AmericanBlackjack.h"

AmericanBlackjack::AmericanBlackjack()
{
    this->actions.push_back(new HitBlackjackAction(this));
}


void AmericanBlackjack::prepareGame()
{
    this->createBoxes(this->app->getPlayers(), 4);
}

void AmericanBlackjack::playGame()
{
    this->requestBets();

    std::vector<std::map<std::string, std::string>> messageParamList;
    u8 actionNumber = 1;

    for (auto& actionName : this->getActionNames())
    {
        messageParamList.push_back({
            std::pair<std::string, std::string>("id", "mes_id_info_action_name"),
            std::pair<std::string, std::string>("number", std::to_string(actionNumber++)),
            std::pair<std::string, std::string>("action", actionName)
        });
    }

    auto validator = ActionInputValidator(1, this->getActionNames().size());
    validator.setAdditionalMessageParams(messageParamList);

    u8 choice = this->app->requestInput<u8>(validator);
}

void AmericanBlackjack::finishGame()
{

}