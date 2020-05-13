#include <algorithm>
#include <random>

#include "AppTypes.h"
#include "AbstractBlackjack.h"

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