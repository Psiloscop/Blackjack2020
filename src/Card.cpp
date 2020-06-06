#include "Card.h"
#include "AppTypes.h"

bool Card::operator==(const Card& card) const
{
    return this->number == card.number && this->suit == card.suit;
}

bool Card::operator!=(const Card& card) const
{
    return this->number != card.number && this->suit != card.suit;
}

CardFace Card::getCardFace()
{
    switch (this->number)
    {
        case CardFace::jack:
            return CardFace::jack;

        case CardFace::queen:
            return CardFace::queen;

        case CardFace::king:
            return CardFace::king;

        case CardFace::ace:
            return CardFace::ace;

        default:
            return CardFace::number;
    }
}

std::string Card::getCardLetter() const
{
    switch (this->number)
    {
        case CardFace::jack:
            return "J";

        case CardFace::queen:
            return "Q";

        case CardFace::king:
            return "K";

        case CardFace::ace:
            return "A";
    }

    return std::to_string(this->number);
}

u8 Card::getCardValue()
{
	switch (this->number)
	{
	case CardFace::jack:
	case CardFace::queen:
	case CardFace::king:
		return 10;

	case CardFace::ace:
		return 11;

	default:
		return this->number;
	}
}

CardSuit Card::getCardSuit()
{
    return this->suit;
}

u8 Card::getMinAceCardValue()
{
    return 1;
}

u8 Card::getMaxAceCardValue()
{
    return 11;
}
