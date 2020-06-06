#pragma once

#include "TemplateInputValidator.h"
#include "Player.h"

class PlayerBetInputValidator: public TemplateInputValidator<u32>
{
protected:
    const Player& player;

public:
    PlayerBetInputValidator(const Player& player)
        : player{player}
    {}

	bool validateValue(const u32& value) override
    {
        return value > 0 && value <= this->player.getCash();
    }

    u32 getValue() override
    {
        return this->value;
    }

    std::vector<ADisplayMessageParam*> getErrorMessageParams() override
    {
        return {
            new ADisplayMessageParam("id", "mes_id_error_player_bet_invalid"),
            new ADisplayMessageParam("cash", std::to_string(player.getCash()))
        };
    }

    std::vector<ADisplayMessageParam*> getRequestMessageParams() override
    {
        return {
            new ADisplayMessageParam("id", "mes_id_info_player_enter_bet"),
            new ADisplayMessageParam("cash", std::to_string(player.getCash()))
        };
    }
};