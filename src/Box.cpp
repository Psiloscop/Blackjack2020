#include "Box.h"

Box::Box(Player& player)
    : player(player)
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

void Box::giveCard(Card& card)
{
    if (this->hands.empty() || this->activeHand >= this->hands.size())
    {
        this->hands.resize(this->hands.size() + 1);
        this->hands[this->activeHand] = {};
    }

    this->hands[this->activeHand].push_back(&card);
}

std::vector<Card*>& Box::getHandCards(u8 handNumber)
{
    if (handNumber > this->hands.size() || handNumber <= 0)
    {
        throw std::out_of_range("Box::getHandCards(handNumber) - handNumber is out of range");
    }

    return this->hands[handNumber - 1];
}

void Box::switchHand(u8 number)
{
    if (number > this->hands.size() || number <= 0)
    {
        throw std::out_of_range("Box::switchHand(number) - number is out of range");
    }

    this->activeHand = number - 1;
}

void Box::setBet(u32 value)
{
    this->bets[this->activeHand] = value;
}

u32 Box::getBet()
{
    return this->bets[this->activeHand];
}
