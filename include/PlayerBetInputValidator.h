#pragma once

#include "TemplateInputValidator.h"
#include "Player.h"

class PlayerBetInputValidator: public TemplateInputValidator<u32>
{
protected:
    Player& player;

public:
    PlayerBetInputValidator(Player& player)
        : player{player}
    {}

	bool validateValue(const u32& value) override
    {
        return value > 0 && value <= this->player.getCash();
    }

    std::map<std::string, std::string> getErrorMessageParams() override
    {
        return {
            std::pair<std::string, std::string>("id", "mes_id_error_player_bet_invalid"),
            std::pair<std::string, std::string>("cash", std::to_string(player.getCash()))
        };
    }

    std::map<std::string, std::string> getRequestMessageParams() override
    {
        return {
            std::pair<std::string, std::string>("id", "mes_id_info_player_enter_bet"),
            std::pair<std::string, std::string>("cash", std::to_string(player.getCash()))
        };
    }
};