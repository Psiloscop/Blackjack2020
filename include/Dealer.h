#pragma once

#include "Player.h"

class Dealer: public Player
{
public:
    Dealer(): Player(nullptr, "Dealer", 0)
    {}

    u32 requestBet() const override;
};