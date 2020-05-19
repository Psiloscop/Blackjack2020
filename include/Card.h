#pragma once

#include <string>

#include "AppTypes.h"

enum CardSuit
{
	club = 1,
	diamond = 2,
	heart = 3,
	spade = 4
};

enum CardFace
{
	jack = 11,
	queen = 12,
	king = 13,
	ace = 14
};

class Card
{
private:
	u8 number;
	CardSuit suit;

public:
	Card(u8 number, CardSuit suit)
		: number(number), suit(suit)
	{}

    bool operator==(const Card& card) const;
    bool operator!=(const Card& card) const;

	std::string getCardFace();

	u8 getCardValue();

	u8 getCardSuit();

    static u8 getMinAceCardValue();

    static u8 getMaxAceCardValue();
};