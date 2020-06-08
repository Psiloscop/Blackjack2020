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
    // Loop must be here. It will be breaking if all boxes are empty.

    this->requestBets();
    this->dealCardsToBoxes(2);
    this->dealCardsToDealer(2);

    u16 actionNumber = 0;
    bool continueGame = true;

    u8 currBoxValue = 0, dealerBoxValue = 0;

    for (auto& currBox : this->getBoxes())
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
        }

        if (!currBox.hasOvertake())
        {
            currBoxValue = currBox.getHandCardsValue();
            dealerBoxValue = this->dealerBox->getHandCardsValue();

            if (currBoxValue == dealerBoxValue)
            {
                this->returnToPlayerItsBet();
            }
            else if (currBoxValue > dealerBoxValue)
            {
                this->payToPlayerForCommonWin();
            }
            else if (currBoxValue < dealerBoxValue)
            {
                // Display Lose message.
            }
        }
        else
        {
            // Display Lose message.
        }

        // Display dealer and player cards
        // Display round status (win, lose, tie)

        // Remove box if its player lost all money
    }
}

void AmericanBlackjack::finishGame()
{

}