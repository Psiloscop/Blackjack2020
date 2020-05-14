#include "Application.h"

void initConsoleApplication()
{
    AbstractBlackjack game;
    ConsoleInputHandler inputHandler;
    ConsoleDisplayHandler displayHandler;

    Application app(game, inputHandler, displayHandler);

    app.addMessageEntity("mes_id_info_player_enter_name", new ConsoleDisplayEntity("Enter player name:", false));
    app.addMessageEntity("mes_id_error_player_name_invalid", new ConsoleDisplayEntity("Player name is invalid."));
    app.addMessageEntity("mes_id_info_player_enter_start_cash", new ConsoleDisplayEntity("Enter player's start cash:", false));
    app.addMessageEntity("mes_id_error_player_cash_invalid", new ConsoleDisplayEntity("Player's start cash must be non-negative integer value and less that 1000"));
    app.addMessageEntity("mes_id_info_player_enter_bet", new ConsoleDisplayEntity("Your cash: ${cash}. Enter your bet:", false));
    app.addMessageEntity("mes_id_error_player_bet_invalid", new ConsoleDisplayEntity("Player's bet must be non-negative integer and no greater than player's cash"));

    app.requestInputToCreatePlayer();
    app.game.createBoxes(app.getPlayers(), 1);
    app.game.requestBets();
}

int main()
{
    initConsoleApplication();

    return 0;
}