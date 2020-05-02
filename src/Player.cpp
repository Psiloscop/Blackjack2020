#include "Player.h"

void Player::increaseCash(u32 amount)
{
	this->cash += amount;
}

void Player::decreaseCash(u32 amount)
{
	this->cash -= amount;
}

template<typename T>
T Player::requestInput(const AbstractInputValidator& validator)
{
	// Should be cin or something

//	if (validator.validateValue())
//	{
//
//	}
}