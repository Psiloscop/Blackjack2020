#include "Application.h"
#include "AppTypes.h"
#include "AmericanBlackjack.h"
#include "ActionSelectInputValidator.h"

AmericanBlackjack::AmericanBlackjack()
{
    this->actions.push_back(new HitBlackjackAction(this));
    this->actions.push_back(new StandBlackjackAction(this));
    this->actions.push_back(new DoubleBlackjackAction(this));
    this->actions.push_back(new InsuranceBlackjackAction(this));
    this->actions.push_back(new SplitBlackjackAction(this));
    this->actions.push_back(new SwitchHandBlackjackAction(this));
}

void AmericanBlackjack::prepareGame()
{
    this->createShoe(1);
    this->shuffleShoe();
    this->createBoxes(this->app->getPlayers(), 4);
}

void AmericanBlackjack::playGame()
{
    bool continueGame = true;
    bool dealerHasBlackjack = false;
    bool dealerHasOvertake = false;
    bool playerHasBlackjack = false;
    bool isInsurancePlayed = false;
    bool isBoxInSplit = false;
    u8 dealerBoxValue = 0;
    u8 currBoxValue = 0;
    u16 actionNumber = 0;
    u32 winCash = 0;

    std::vector<std::vector<ADisplayMessageParam*>> messageParamList;

    while (!this->boxes.empty())
    {
        continueGame = true;
        dealerHasBlackjack = false;
        dealerHasOvertake = false;
        playerHasBlackjack = false;
        isInsurancePlayed = false;
        isBoxInSplit = false;
        dealerBoxValue = 0;
        currBoxValue = 0;
        actionNumber = 0;
        winCash = 0;

        AbstractBlackjack::clearMessageParamList(messageParamList);

        this->requestBets();
        this->dealCardsToBoxes(2);
        this->dealCardsToDealer(2);

        auto& boxes = this->getBoxes();
        std::vector<u8> boxIndexes(boxes.size());
        std::iota(std::begin(boxIndexes), std::end(boxIndexes), 0);

        loopBoxes:
        for (auto it = boxIndexes.begin(); it != boxIndexes.end(); it++)
        {
            auto& currBox = boxes[*it];

            if (currBox.hasBlackjack())
            {
                messageParamList.push_back({
                    new ADisplayMessageParam("id", "mes_id_info_player_cards"),
                    new ADisplayMessageParam("name", currBox.getPlayer().getName()),
                    new DisplayMessageParamPlayerCards("cards", "", currBox.getAllCards(), currBox.getCurrentHandNumber())
                });
                messageParamList.push_back({
                    new ADisplayMessageParam("id", "mes_id_info_game_result_blackjack"),
                    new ADisplayMessageParam("name", currBox.getPlayer().getName())
                });
                this->app->displayMessages(messageParamList);

                AbstractBlackjack::clearMessageParamList(messageParamList);

                continue;
            }

            while (continueGame)
            {
                auto actionIndexes = this->getAvailableActionIndexes();
                auto actionNames = this->getActionNames(actionIndexes);
                auto validator = ActionSelectInputValidator(actionIndexes.size(), "Action", actionNames,
                                                            this->getDealerBox(), this->getCurrentBox());
                actionNumber = this->app->requestInput<u16>(validator);
                actionNumber--;

                continueGame = this->actions[actionIndexes[actionNumber]]->execute();

                if (continueGame)
                {
                    continueGame = !currBox.hasOvertake(currBox.isBoxInSplit());
                }
            }

            if (currBox.hasOvertake(currBox.isBoxInSplit()))
            {
                messageParamList.push_back({
                    new ADisplayMessageParam("id", "mes_id_info_player_cards"),
                    new ADisplayMessageParam("name", currBox.getPlayer().getName()),
                    new DisplayMessageParamPlayerCards("cards", "", currBox.getAllCards(), currBox.getCurrentHandNumber())
                });
                messageParamList.push_back({
                    new ADisplayMessageParam("id", "mes_id_info_game_result_lose"),
                    new ADisplayMessageParam("name", currBox.getPlayer().getName()),
                    new ADisplayMessageParam("lostCash", std::to_string(currBox.getAllBets()))
                });
                messageParamList.push_back({
                    new ADisplayMessageParam("id", "mes_id_info_game_result_overtake"),
                    new ADisplayMessageParam("name", currBox.getPlayer().getName())
                });
                this->app->displayMessages(messageParamList);

                AbstractBlackjack::clearMessageParamList(messageParamList);
            }
        }

        if (!isInsurancePlayed && !this->insuredBoxIndexes.empty() && !this->dealerBox->hasBlackjack())
        {
            boxIndexes.clear();
            boxIndexes.resize(this->insuredBoxIndexes.size());
            boxIndexes.assign(this->insuredBoxIndexes.begin(), this->insuredBoxIndexes.end());

            // Grab user's insurances
            for (u8 boxIndex : boxIndexes)
            {
                auto& currBox = boxes[boxIndex];

                currBox.updateBet(currBox.getBet() / 3 * 2);
            }

            messageParamList.push_back({
                new ADisplayMessageParam("id", "mes_id_info_game_result_insurance_lose")
            });
            this->app->displayMessages(messageParamList);

            AbstractBlackjack::clearMessageParamList(messageParamList);

            continueGame = true;
            isInsurancePlayed = true;

            goto loopBoxes; // I know it's awful but it fits perfectly in this case.
        }

        while (!this->dealerBox->hasBlackjack() && !this->dealerBox->isAllowedMaxValueReached())
        {
            this->dealerBox->giveCard(this->getNextCard());
        }

        dealerBoxValue = this->dealerBox->getHandCardsValue();
        dealerHasBlackjack = this->dealerBox->hasBlackjack();
        dealerHasOvertake = this->dealerBox->getHandCardsValue() > 21;

        for (auto boxIt = boxes.begin(); boxIt != boxes.end();)
        {
            messageParamList.push_back({
                new ADisplayMessageParam("id", "mes_id_info_dealer_cards"),
                new DisplayMessageParamDealerCards("cards", "", this->dealerBox->getHandCards(), false)
            });
            messageParamList.push_back({
                new ADisplayMessageParam("id", "mes_id_info_player_cards"),
                new ADisplayMessageParam("name", boxIt->getPlayer().getName()),
                new DisplayMessageParamPlayerCards("cards", "", boxIt->getAllCards(), boxIt->getCurrentHandNumber())
            });

            isBoxInSplit = boxIt->isBoxInSplit();
            currBoxValue = boxIt->getHandCardsValue();
            playerHasBlackjack = boxIt->hasBlackjack();

            if (!boxIt->hasOvertake(isBoxInSplit))
            {
                if (isBoxInSplit)
                {
                    messageParamList.push_back({
                        new ADisplayMessageParam("id", "mes_id_info_game_result_split"),
                        new ADisplayMessageParam("name", boxIt->getPlayer().getName())
                    });

                    for (u8 handNumber = 1; handNumber <= boxIt->getHandCount(); handNumber++)
                    {
                        boxIt->switchHand(handNumber);

                        if (dealerHasBlackjack)
                        {
                            messageParamList.push_back({
                                new ADisplayMessageParam("id", "mes_id_info_game_result_blackjack_lose"),
                                new ADisplayMessageParam("name", boxIt->getPlayer().getName()),
                            });

                            continue;
                        }
                        else if (dealerHasOvertake && !boxIt->hasOvertake())
                        {
                            winCash = this->payToPlayerForCommonWin();

                            messageParamList.push_back({
                                new ADisplayMessageParam("id", "mes_id_info_game_result_dealer_overtake")
                            });
                            messageParamList.push_back({
                                new ADisplayMessageParam("id", "mes_id_info_game_result_split_hand_win"),
                                new ADisplayMessageParam("number", std::to_string(handNumber)),
                                new ADisplayMessageParam("winCash", std::to_string(winCash))
                            });

                            continue;
                        }

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
                    if (dealerHasOvertake)
                    {
                        winCash = this->payToPlayerForCommonWin();

                        messageParamList.push_back({
                            new ADisplayMessageParam("id", "mes_id_info_game_result_dealer_overtake")
                        });
                        messageParamList.push_back({
                            new ADisplayMessageParam("id", "mes_id_info_game_result_win"),
                            new ADisplayMessageParam("name", boxIt->getPlayer().getName()),
                            new ADisplayMessageParam("winCash", std::to_string(winCash))
                        });
                    }
                    else if (dealerHasBlackjack && playerHasBlackjack)
                    {
                        this->returnToPlayerItsBet();

                        messageParamList.push_back({
                            new ADisplayMessageParam("id", "mes_id_info_game_result_blackjack_tie"),
                            new ADisplayMessageParam("name", boxIt->getPlayer().getName())
                        });
                    }
                    else if (dealerHasBlackjack && !playerHasBlackjack)
                    {
                        u8 boxIndex = std::distance(boxes.begin(), boxIt);
                        auto tmpIt = find(this->insuredBoxIndexes.begin(), this->insuredBoxIndexes.end(), boxIndex);

                        if (tmpIt != this->insuredBoxIndexes.end())
                        {
                            this->returnToPlayerItsBet();

                            messageParamList.push_back({
                                new ADisplayMessageParam("id", "mes_id_info_game_result_blackjack_insurance"),
                                new ADisplayMessageParam("name", boxIt->getPlayer().getName())
                            });
                        }
                        else
                        {
                            messageParamList.push_back({
                                new ADisplayMessageParam("id", "mes_id_info_game_result_blackjack_lose"),
                                new ADisplayMessageParam("name", boxIt->getPlayer().getName())
                            });
                        }
                    }
                    else if (!dealerHasBlackjack && playerHasBlackjack)
                    {
                        this->payToPlayerForBlackjack();

                        messageParamList.push_back({
                            new ADisplayMessageParam("id", "mes_id_info_game_result_blackjack"),
                            new ADisplayMessageParam("name", boxIt->getPlayer().getName())
                        });
                    }
                    else if (currBoxValue == dealerBoxValue)
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
                    new ADisplayMessageParam("name",  boxIt->getPlayer().getName())
                });
                messageParamList.push_back({
                    new ADisplayMessageParam("id", "mes_id_info_game_result_lose"),
                    new ADisplayMessageParam("name",  boxIt->getPlayer().getName()),
                    new ADisplayMessageParam("lostCash", std::to_string(boxIt->getAllBets()))
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

        this->app->displayMessages(messageParamList);

        this->dealerBox->resetBox();

        if (!this->insuredBoxIndexes.empty())
        {
            this->insuredBoxIndexes.clear();
        }
    }
}

void AmericanBlackjack::finishGame()
{

}