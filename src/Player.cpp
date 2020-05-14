#include "Player.h"
#include "Application.h"

void Player::increaseCash(u32 amount)
{
	this->cash += amount;
}

void Player::decreaseCash(u32 amount)
{
	this->cash -= amount;
}

std::string Player::getName() const
{
    return this->name;
}

u32 Player::getCash() const
{
    return this->cash;
}

u32 Player::requestBet() const
{
    PlayerBetInputValidator validator(*this);

    return this->app->template requestInput<u32>(validator);
}