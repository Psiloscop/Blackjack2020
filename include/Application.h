#ifndef __APPLICATION_H_INCLUDED__
#define __APPLICATION_H_INCLUDED__

class AbstractBlackjack;
class InputHandler;
class Player;

#include <vector>

#include "AbstractBlackjack.h"
#include "AbstractDisplayHandler.h"
#include "AbstractDisplayEntity.h"
#include "InputHandler.h"

class Application
{
private:
    AbstractBlackjack* game;

    InputHandler* inputHandler;

    std::vector<Player*> players;

public:
    void createPlayer();

    void displayMessage(std::string messageId) const;
    void displayMessages(std::string messageId[]) const;
};

#endif // __APPLICATION_H_INCLUDED__