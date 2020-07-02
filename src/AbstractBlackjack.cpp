#include <algorithm>
#include <random>

#include "Application.h"
#include "AppTypes.h"
#include "AbstractBlackjack.h"

void AbstractBlackjack::assignApp(Application* _app)
{
    this->app = _app;
}

std::vector<u8> AbstractBlackjack::getAvailableActionIndexes(Box& currentBox)
{
    std::vector<u8> availableActionIndexes;
    u8 index = 0;

    for (auto& action : this->actions)
    {
        if (action->isAvailable(&currentBox))
        {
            availableActionIndexes.push_back(index);
        }

        index++;
    }

    return availableActionIndexes;
}

std::vector<std::string> AbstractBlackjack::getActionNames(const std::vector<u8>& actionIndexes)
{
    std::vector<std::string> actionNames;
    actionNames.reserve(actionIndexes.size());

    for (u8 index : actionIndexes)
    {
        actionNames.push_back(this->actions[index]->getName());
    }

    return actionNames;
}

std::vector<Box>& AbstractBlackjack::getBoxes()
{
    return this->boxes;
}

u8 AbstractBlackjack::getBoxIndex(Box& box) const
{
    const Box* boxPtr = &box;

    return std::distance(this->boxes.data(), boxPtr);
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

//    std::random_device rd;
//    std::mt19937 e{rd()}; // or std::default_random_engine e{rd()};
//    std::shuffle(std::begin(this->shoe), std::end(this->shoe), e);

    std::srand(time(nullptr));

    u16 firstIdx, secondIdx, size = this->shoe.size();

    for (u16 idx = 0; idx < size; idx++) {
        firstIdx = std::rand() % size;
        secondIdx = std::rand() % size;

        std::swap(this->shoe[firstIdx], this->shoe[secondIdx]);
    }

    return this->shoe;
}

Card* AbstractBlackjack::getNextCard()
{
    if (this->shoeIndex >= this->shoe.size())
    {
        throw std::out_of_range("AbstractBlackjack::getNextCard() - shoeIndex is out of range");
    }

    return &this->shoe[this->shoeIndex++];
}

std::vector<Box>& AbstractBlackjack::createBoxes(std::vector<Player>& players, u8 boxCount)
{
    u8 playerCount = players.size();

    for (u8 boxNumber = 1, playerIndex = 0;
            boxNumber <= boxCount && boxNumber <= playerCount;
            boxNumber++, playerIndex++)
    {
        Box box(&players[playerIndex], this->allowedMaxValueForPlayer);

        this->boxes.push_back(box);
    }

    this->dealerBox = new Box(&this->dealer, this->allowedMaxValueForDealer);

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
            box.giveCard(this->getNextCard());
        }
    }

    // For "Split" action testing
//    this->getBoxes()[0].giveCard(new Card(10, CardSuit::club));
//    this->getBoxes()[0].giveCard(new Card(10, CardSuit::diamond));
}

void AbstractBlackjack::dealCardsToDealer(u8 cardToDealer)
{
    Card* card = nullptr;

    for (u8 cardNumber = 1; cardNumber <= cardToDealer; cardNumber++)
    {
        this->dealerBox->giveCard(this->getNextCard());
    }

    // For "Insurance" action testing
//    this->dealerBox->giveCard(new Card(CardFace::ace, CardSuit::club));
//    this->dealerBox->giveCard(new Card(10, CardSuit::diamond));
//    this->dealerBox->giveCard(new Card(5, CardSuit::spade));
}

std::vector<Card*>& AbstractBlackjack::getDealerCards()
{
    return this->dealerBox->getHandCards();
}

u32 AbstractBlackjack::payToPlayerForBlackjack(Box* box)
{
    u32 winCash = box->getBet() * 1.5;

    box->getPlayer().increaseCash(box->getBet() + winCash);

    return winCash;
}

u32 AbstractBlackjack::payToPlayerForCommonWin(Box* box)
{
    u32 winCash = box->getBet();

    box->getPlayer().increaseCash(box->getBet() + winCash);

    return winCash;
}

u32 AbstractBlackjack::returnToPlayerItsBet(Box* box)
{
    box->getPlayer().increaseCash(box->getBet());

    return 0;
}

void AbstractBlackjack::addInsuredBoxIndex(u8 index)
{
    if (!this->hasInsuredBoxIndex(index))
    {
        this->insuredBoxIndexes.push_back(index);
    }
}

bool AbstractBlackjack::hasInsuredBoxIndex(u8 index) const
{
    for (auto _index : this->insuredBoxIndexes)
    {
        if (index == _index)
        {
            return true;
        }
    }

    return false;
}

void AbstractBlackjack::clearMessageParamList(std::vector<std::vector<ADisplayMessageParam*>>& messageParamList)
{
    for (auto& params : messageParamList)
    {
        for (auto param : params)
        {
            delete param;
        }
    }

    messageParamList.clear();
}