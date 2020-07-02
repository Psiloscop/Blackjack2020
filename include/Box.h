#pragma once

#include <vector>
#include <algorithm>

#include "Player.h"
#include "Card.h"

class Box
{
protected:
    Player* player;

	std::vector<std::vector<Card*>> hands = {};

    std::vector<u32> bets = {0};

    u8 allowedMaxValue = 21;

    u8 activeHand = 0;

public:
    Box(Player*, u8);

    void assignPlayer(Player*);

    void resetBox();

    Player& getPlayer() const;

    void giveCard(Card*);

    std::vector<std::vector<Card*>>& getAllCards();

    std::vector<Card*>& getHandCards();

    u8 getHandCount() const;

    u8 getCurrentHandNumber() const;

    u8 getHandCardsCount();

    u8 getHandCardsValue();

    bool isAllowedMaxValueReached();

    void switchHand(u8);

    void setBet(u32, bool = false);

    void updateBet(u32);

    u32 getBet();

    u32 getAllBets();

    std::vector<u8> getPlayableHandNumbers();

    bool isBoxInSplit();

    bool hasBlackjack();

    bool hasOvertake(bool = false);
};