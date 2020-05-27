#include "Application.h"
#include "AmericanBlackjack.h"

void initConsoleApplication()
{
    AmericanBlackjack game;
    ConsoleInputHandler inputHandler;
    ConsoleDisplayHandler displayHandler;

    Application app(game, inputHandler, displayHandler);

    app.addMessageEntity("mes_id_info_option_name", new ConsoleDisplayEntity("{number}. {option}"));
    app.addMessageEntity("mes_id_info_choose_option", new ConsoleDisplayEntity("Choose {optionName} (enter number from {min} to {max}):", false));
    app.addMessageEntity("mes_id_error_invalid_choice", new ConsoleDisplayEntity("Invalid {optionName} choice."));

    app.addMessageEntity("mes_id_info_player_enter_name", new ConsoleDisplayEntity("Enter player name:", false));
    app.addMessageEntity("mes_id_error_player_name_invalid", new ConsoleDisplayEntity("Player name is invalid."));
    app.addMessageEntity("mes_id_info_player_enter_start_cash", new ConsoleDisplayEntity("Enter player's start cash:", false));
    app.addMessageEntity("mes_id_error_player_cash_invalid", new ConsoleDisplayEntity("Player's start cash must be non-negative integer value and less that 1000"));
    app.addMessageEntity("mes_id_info_player_enter_bet", new ConsoleDisplayEntity("Your cash: ${cash}. Enter your bet:", false));
    app.addMessageEntity("mes_id_error_player_bet_invalid", new ConsoleDisplayEntity("Player's bet must be non-negative integer and no greater than player's cash"));
    app.addMessageEntity("mes_id_info_player_cards", new CardsDisplayEntity("Player: {cards}"));
    app.addMessageEntity("mes_id_info_dealer_cards", new CardsDisplayEntity("Dealer: {cards}"));

    app.requestInputToCreatePlayer();

    app.startGame();
}

int main()
{
    initConsoleApplication();

    return 0;
}