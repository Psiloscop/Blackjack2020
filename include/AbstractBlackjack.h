#ifndef __ABSTRACT_BLACKJACK_H_INCLUDED__
#define __ABSTRACT_BLACKJACK_H_INCLUDED__

class BaseApplication;
class AbstractBlackjackAction;
class Box;

#include <vector>

#include "BaseApplication.h"
#include "AppTypes.h"
#include "AbstractBlackjackAction.h"
#include "Box.h"
#include "Card.h"

class AbstractBlackjack
{
private:
    BaseApplication* app;

	std::vector<Box*> boxes;

	std::vector<Card*> shoe;

	std::vector<AbstractBlackjackAction> actions;

public:
    virtual std::vector<Card*>& createShoe(u8 deckCount);

    std::vector<Card*>& shuffleShoe();
};

#endif // __ABSTRACT_BLACKJACK_H_INCLUDED__