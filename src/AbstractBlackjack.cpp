#include <algorithm>
#include <random>

#include "Application.h"
#include "AppTypes.h"
#include "AbstractBlackjack.h"

std::vector<Box>& AbstractBlackjack::getBoxes()
{
    return this->boxes;
}

Box& AbstractBlackjack::getDealerBox()
{
    return *this->dealerBox;
}

std::vector<Card>& AbstractBlackjack::createShoe(u8 deckCount)
{
	while (deckCount > 0)
	{
		for (u8 suitNumber = 1; suitNumber <= 4; suitNumber++)
		{
			for (u8 cardNumber = 2; cardNumber <= 14; cardNumber++)
			{
			    Card card(cardNumber, CardSuit(suitNumber));

				this->shoe.push_back(card);
			}
		}

		deckCount--;
	}

	return this->shoe;
}

std::vector<Card>& AbstractBlackjack::shuffleShoe()
{
//    auto rng = std::default_random_engine(std::random_device{}());
//    std::shuffle(std::begin(this->shoe), std::end(this->shoe), rng);

    std::random_device rd;
    std::mt19937 e{rd()}; // or std::default_random_engine e{rd()};
    std::shuffle(std::begin(this->shoe), std::end(this->shoe), e);

    return this->shoe;
}

std::vector<Box>& AbstractBlackjack::createBoxes(std::vector<Player>& players, u8 boxCount)
{
    u8 playerCount = players.size();

    for (u8 boxNumber = 1, playerIndex = 0;
            boxNumber <= boxCount && boxNumber <= playerCount;
            boxNumber++, playerIndex++)
    {
        Box box(players[playerIndex], this->allowedMaxValueForPlayer);

        this->boxes.push_back(box);
    }

    this->dealerBox = new Box(this->dealer, this->allowedMaxValueForDealer);

    return this->boxes;
}

void AbstractBlackjack::requestBets()
{
    for (auto& box : this->getBoxes())
    {
        box.setBet(box.getPlayer().requestBet());
    }
}

void AbstractBlackjack::dealCardsToBoxes(u8 cardPerBox)
{
    for (auto& box : this->getBoxes())
    {
        for (u8 cardNumber = 1; cardNumber <= cardPerBox; cardNumber++)
        {
            box.giveCard(&(this->shoe[this->shoeIndex++]));
        }
    }
}

void AbstractBlackjack::dealCardsToDealer(u8 cardToDealer)
{
    Card* card = nullptr;

    for (u8 cardNumber = 1; cardNumber <= cardToDealer; cardNumber++)
    {
        card = &this->shoe[this->shoeIndex++];

        this->dealerBox->giveCard(card);
    }
}

std::vector<Card*>& AbstractBlackjack::getDealerCards()
{
    return this->dealerBox->getHandCards();
}

BoxStatus AbstractBlackjack::getBoxStatus()
{
    bool hasBlackjack = this->boxes[this->boxIndex].hasBlackjack();
    bool hasOvertake = this->boxes[this->boxIndex].hasOvertake();

    if (hasBlackjack)
    {
        return BoxStatus::blackjack;
    }
    else if (hasOvertake)
    {
        return BoxStatus::overtook;
    }
    else
    {
        return BoxStatus::ok;
    }
}

RoundResult AbstractBlackjack::getRoundResult()
{
    u8 dealerValue = this->dealerBox->getHandCardsValue();
    u8 playerValue = this->boxes[this->boxIndex].getHandCardsValue();

    if (playerValue > dealerValue)
    {
        return RoundResult::win;
    }
    else if (playerValue < dealerValue)
    {
        return RoundResult::lose;
    }
    else
    {
        return RoundResult::tie;
    }
}

void AbstractBlackjack::payToPlayerForBlackjack()
{
    this->boxes[this->boxIndex].getPlayer().increaseCash(
            this->boxes[this->boxIndex].getBet() + this->boxes[this->boxIndex].getBet() * 1.5);
}

void AbstractBlackjack::payToPlayerForCommonWin()
{
    this->boxes[this->boxIndex].getPlayer().increaseCash(this->boxes[this->boxIndex].getBet() * 2);
}

void AbstractBlackjack::returnToPlayerItsBet()
{
    this->boxes[this->boxIndex].getPlayer().increaseCash(this->boxes[this->boxIndex].getBet());
}
