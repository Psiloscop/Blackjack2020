#include "Application.h"
#include "AppTypes.h"
#include "AmericanBlackjack.h"
#include "ActionSelectInputValidator.h"

AmericanBlackjack::AmericanBlackjack()
{
    this->actions.push_back(new HitBlackjackAction(this));
}

void AmericanBlackjack::prepareGame()
{
    this->createShoe(1);
    this->shuffleShoe();
    this->createBoxes(this->app->getPlayers(), 4);
}

void AmericanBlackjack::playGame()
{
    u16 actionNumber = 0;
    bool continueGame = true;
    u32 winCash = 0;
    u8 currBoxValue = 0;
    u8 dealerBoxValue = 0;
    bool isBoxInSplit = false;

    std::vector<std::vector<ADisplayMessageParam*>> messageParamList;

    while (!this->boxes.empty())
    {
        actionNumber = 0;
        continueGame = true;
        winCash = 0;
        currBoxValue = 0;
        dealerBoxValue = 0;
        isBoxInSplit = false;

        AbstractBlackjack::clearMessageParamList(messageParamList);

        this->requestBets();
        this->dealCardsToBoxes(2);
        this->dealCardsToDealer(2);

        auto& boxes = this->getBoxes();

        for (auto& currBox : boxes)
        {
            if (currBox.hasBlackjack())
            {
                // Check if dealer has one. If it hasn't then pay for Blackjack otherwise offer insurance.
            }

            while (continueGame)
            {
                // Append/Remove actions depending on game state.

                auto actionNames = this->getActionNames();
                auto validator = ActionSelectInputValidator(this->getActionNames().size(), "Action", actionNames,
                                                            this->getDealerBox(), this->getCurrentBox());
                actionNumber = this->app->requestInput<u16>(validator);
                actionNumber--;

                continueGame = this->actions[actionNumber]->execute();

                if (continueGame)
                {
                    continueGame = !currBox.hasOvertake(currBox.isBoxInSplit());
                }
            }

            if (currBox.hasOvertake(currBox.isBoxInSplit()))
            {
                messageParamList.push_back({
                    new ADisplayMessageParam("id", "mes_id_info_game_result_overtake"),
                    new ADisplayMessageParam("name", currBox.getPlayer().getName())
                });
                messageParamList.push_back({
                    new ADisplayMessageParam("id", "mes_id_info_game_result_lose"),
                    new ADisplayMessageParam("name", currBox.getPlayer().getName()),
                    new ADisplayMessageParam("lostCash", std::to_string(currBox.getBet()))
                });
                this->app->displayMessages(messageParamList); // Displays both "Overtake" and "Lose" messages.
            }

            AbstractBlackjack::clearMessageParamList(messageParamList);
        }

        while (!this->dealerBox->isAllowedMaxValueReached())
        {
            this->dealerBox->giveCard(this->getNextCard());
        }

        dealerBoxValue = this->dealerBox->getHandCardsValue();

        messageParamList.push_back({
                new ADisplayMessageParam("id", "mes_id_info_dealer_cards"),
                new DisplayMessageParamDealerCards("cards", "", this->dealerBox->getHandCards(), false)
        });

        for (auto boxIt = boxes.begin(); boxIt != boxes.end();)
        {
            messageParamList.push_back({
                new ADisplayMessageParam("id", "mes_id_info_player_cards"),
                new ADisplayMessageParam("name", boxIt->getPlayer().getName()),
                new DisplayMessageParamPlayerCards("cards", "", boxIt->getAllCards(), boxIt->getCurrentHandNumber())
            });

            isBoxInSplit = boxIt->isBoxInSplit();

            if (!boxIt->hasOvertake(isBoxInSplit))
            {
                if (isBoxInSplit)
                {
                    messageParamList.push_back({
                        new ADisplayMessageParam("id", "mes_id_info_game_result_split")
                    });

                    for (u8 handNumber = 1; handNumber <= boxIt->getHandCardsCount(); handNumber++)
                    {
                        boxIt->switchHand(handNumber);

                        currBoxValue = boxIt->getHandCardsValue();

                        if (currBoxValue == dealerBoxValue)
                        {
                            this->returnToPlayerItsBet();

                            messageParamList.push_back({
                                new ADisplayMessageParam("id", "mes_id_info_game_result_split_hand_tie"),
                                new ADisplayMessageParam("number", std::to_string(handNumber))
                            });
                        }
                        else if (currBoxValue > dealerBoxValue)
                        {
                            winCash = this->payToPlayerForCommonWin();

                            messageParamList.push_back({
                                new ADisplayMessageParam("id", "mes_id_info_game_result_split_hand_win"),
                                new ADisplayMessageParam("number", std::to_string(handNumber)),
                                new ADisplayMessageParam("winCash", std::to_string(winCash))
                            });
                        }
                        else if (currBoxValue < dealerBoxValue)
                        {
                            messageParamList.push_back({
                                new ADisplayMessageParam("id", "mes_id_info_game_result_split_hand_lose"),
                                new ADisplayMessageParam("number", std::to_string(handNumber)),
                                new ADisplayMessageParam("lostCash", std::to_string(boxIt->getBet()))
                            });
                        }
                    }
                }
                else
                {
                    if (currBoxValue == dealerBoxValue)
                    {
                        this->returnToPlayerItsBet();

                        messageParamList.push_back({
                            new ADisplayMessageParam("id", "mes_id_info_game_result_tie"),
                            new ADisplayMessageParam("name", boxIt->getPlayer().getName())
                        });
                    }
                    else if (currBoxValue > dealerBoxValue)
                    {
                        winCash = this->payToPlayerForCommonWin();

                        messageParamList.push_back({
                            new ADisplayMessageParam("id", "mes_id_info_game_result_win"),
                            new ADisplayMessageParam("name", boxIt->getPlayer().getName()),
                            new ADisplayMessageParam("winCash", std::to_string(winCash))
                        });
                    }
                    else if (currBoxValue < dealerBoxValue)
                    {
                        messageParamList.push_back({
                            new ADisplayMessageParam("id", "mes_id_info_game_result_lose"),
                            new ADisplayMessageParam("name", boxIt->getPlayer().getName()),
                            new ADisplayMessageParam("lostCash", std::to_string(boxIt->getBet()))
                        });
                    }
                }
            }
            else
            {
                messageParamList.push_back({
                    new ADisplayMessageParam("id", "mes_id_info_game_result_overtake"),
                    new ADisplayMessageParam("name",  boxIt->getPlayer().getName()),
                    });
                messageParamList.push_back({
                    new ADisplayMessageParam("id", "mes_id_info_game_result_lose"),
                    new ADisplayMessageParam("name",  boxIt->getPlayer().getName()),
                    new ADisplayMessageParam("lostCash", std::to_string(boxIt->getBet()))
                });
            }

            if (boxIt->getPlayer().getCash() == 0)
            {
                boxIt = boxes.erase(boxIt);

                messageParamList.push_back({
                    new ADisplayMessageParam("id", "mes_id_info_game_result_player_left"),
                    new ADisplayMessageParam("name",  boxIt->getPlayer().getName())
                });
            }
            else
            {
                boxIt->resetBox();

                boxIt++;
            }
        }

        this->dealerBox->resetBox();

        this->app->displayMessages(messageParamList);
    }
}

void AmericanBlackjack::finishGame()
{

}