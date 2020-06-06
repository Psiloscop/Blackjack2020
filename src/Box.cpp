#include "Box.h"

Box::Box(Player& player, u8 allowedMaxValue)
    : player{player}, allowedMaxValue{allowedMaxValue}
{}

void Box::assignPlayer(Player& _player)
{
    this->player = _player;
}

Player& Box::getPlayer() const
{
    return this->player;
}

void Box::resetBox()
{
    this->hands.clear();
    this->bets.clear();

    this->bets = {0};
    this->activeHand = 0;
}

void Box::giveCard(Card* card)
{
    if (this->hands.empty() || this->activeHand >= this->hands.size())
    {
        this->hands.resize(this->hands.size() + 1);
        this->hands[this->activeHand] = {};
    }

    this->hands[this->activeHand].push_back(card);
}

std::vector<std::vector<Card*>>& Box::getAllCards()
{
    return this->hands;
}

std::vector<Card*>& Box::getHandCards()
{
    return this->hands[this->activeHand];
}

u8 Box::getHandCardsCount()
{
    if (this->hands.size() == 0)
    {
        return 0;
    }

    return this->hands[this->activeHand].size();
}


u8 Box::getHandCardsValue()
{
    u8 value = 0;
    u8 aceCardCount = 0;

    for (auto& card : this->hands[this->activeHand])
    {
        if (card->getCardFace() != CardFace::ace)
        {
            value += card->getCardValue();
        }
        else
        {
            aceCardCount++;
        }
    }

    while (aceCardCount > 0)
    {
        value += (this->allowedMaxValue - (value + Card::getMinAceCardValue() * aceCardCount) >= Card::getMaxAceCardValue())
                ? Card::getMaxAceCardValue() : Card::getMinAceCardValue();

        aceCardCount--;
    }

    return value;
}

void Box::switchHand(u8 number)
{
    if (number > this->hands.size() + 1 || number <= 0)
    {
        throw std::out_of_range("Box::switchHand(number) - number is out of range");
    }

    this->activeHand = number - 1;
}

void Box::setBet(u32 value)
{
    this->bets[this->activeHand] = value;

    this->player.decreaseCash(value);
}

u32 Box::getBet()
{
    return this->bets[this->activeHand];
}

bool Box::isBoxInSplit()
{
    return this->hands.size() > 1;
}

bool Box::hasBlackjack()
{
    if (this->hands.size() > 1)
    {
        return false;
    }

    auto& cards = this->hands[this->activeHand];

    return cards.size() == 2 && (cards[0]->getCardValue() == 10 && cards[1]->getCardValue() == 11 ||
        cards[1]->getCardValue() == 10 && cards[0]->getCardValue() == 11);
}

bool Box::hasOvertake()
{

    return this->getHandCardsValue() > this->allowedMaxValue;
}
