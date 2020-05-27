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
    this->dealCardsToBoxes(2);
    this->dealCardsToDealer(2);

    auto actionNames = this->getActionNames();
    auto validator = OptionInputValidator(this->getActionNames().size(), "Action", actionNames);



//    std::vector<std::map<std::string, std::string>> messageParamList = {};
//    u8 number = 1;
//
//    for (Card* card : this->getCurrentBox().getHandCards())
//    {
//        messageParamList.push_back({
//            std::pair<std::string, std::string>("id", "mes_id_info_player_cards"),
//            std::pair<std::string, std::string>("cards", card->getCardLetter() + L" " + card->getCardSuit()),
//        });
//    }
//
//    this->setAdditionalMessageParams(messageParamList);



    u8 actionNumber = this->app->requestInput<u8>(validator);
}

void AmericanBlackjack::finishGame()
{

}