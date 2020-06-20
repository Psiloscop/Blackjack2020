#pragma once

#include "Card.h"

class CardHidden: public Card
{
public:
    CardHidden(): Card(1, CardSuit::hidden)
	{}
};