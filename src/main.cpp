#include "Application.h"
#include "AmericanBlackjack.h"

void initConsoleApplication()
{
    AmericanBlackjack game;
    ConsoleInputHandler inputHandler;
    ConsoleDisplayHandler displayHandler;

    Application app(game, inputHandler, displayHandler);

    app.addMessageEntity("mes_id_info_option_name", new ADisplayEntity("{number}. {option}"));
    app.addMessageEntity("mes_id_info_choose_option", new ADisplayEntity("Choose {optionName} (enter number from {min} to {max}):", false));
    app.addMessageEntity("mes_id_error_invalid_choice", new ADisplayEntity("Invalid {optionName} choice."));

    app.addMessageEntity("mes_id_info_player_enter_name", new ADisplayEntity("Enter player name:", false));
    app.addMessageEntity("mes_id_error_player_name_invalid", new ADisplayEntity("Player name is invalid."));
    app.addMessageEntity("mes_id_info_player_enter_start_cash", new ADisplayEntity("Enter player's start cash:", false));
    app.addMessageEntity("mes_id_error_player_cash_invalid", new ADisplayEntity("Player's start cash must be non-negative integer value and less that 1000"));
    app.addMessageEntity("mes_id_info_player_enter_bet", new ADisplayEntity("Your cash: ${cash}. Enter your bet:", false));
    app.addMessageEntity("mes_id_error_player_bet_invalid", new ADisplayEntity("Player's bet must be non-negative integer and no greater than player's cash"));
    app.addMessageEntity("mes_id_info_dealer_cards", new CardsDisplayEntity("Dealer: {cards}"));
    app.addMessageEntity("mes_id_info_player_cards", new CardsDisplayEntity("Player ({name}): {cards}"));

    app.addMessageEntity("mes_id_info_game_result_dealer_cards", new CardsDisplayEntity("Dealer: {cards}"));
    app.addMessageEntity("mes_id_info_game_result_player_cards", new CardsDisplayEntity("Player ({name}): {cards}"));
    app.addMessageEntity("mes_id_info_game_result_win", new ADisplayEntity("Player {name} win! Received ${winCash}", true, true));
    app.addMessageEntity("mes_id_info_game_result_lose", new ADisplayEntity("Player {name} lose! Lost ${lostCash}", true, true));
    app.addMessageEntity("mes_id_info_game_result_tie", new ADisplayEntity("Player {name} tie! He's received his bet back.", true, true));
    app.addMessageEntity("mes_id_info_game_result_overtake", new ADisplayEntity("Player {name} busts!", true, true));
    app.addMessageEntity("mes_id_info_game_result_dealer_overtake", new ADisplayEntity("Dealer busts!", true, true));
    app.addMessageEntity("mes_id_info_game_result_blackjack", new ADisplayEntity("Player {name} has Blackjack!", true, true));
    app.addMessageEntity("mes_id_info_game_result_blackjack_tie", new ADisplayEntity("Player {name} has Blackjack, but the dealer too. Tie.", true, true));
    app.addMessageEntity("mes_id_info_game_result_blackjack_lose", new ADisplayEntity("Dealer has blackjack. Player {name} lose.", true, true));
    app.addMessageEntity("mes_id_info_game_result_blackjack_insurance", new ADisplayEntity("Dealer has blackjack. Player {name} received his bet back.", true, true));
    app.addMessageEntity("mes_id_info_game_result_insurance_lose", new ADisplayEntity("Dealer has no blackjack. Players's insurances are lost.", true, true));
    app.addMessageEntity("mes_id_info_game_result_split", new ADisplayEntity("Player {name} split:", true, true));
    app.addMessageEntity("mes_id_info_game_result_split_hand_win", new ADisplayEntity("Hand {number}: Win! Received ${winCash}", true, true));
    app.addMessageEntity("mes_id_info_game_result_split_hand_lose", new ADisplayEntity("Hand {number}: Lose! Lost ${lostCash}", true, true));
    app.addMessageEntity("mes_id_info_game_result_split_hand_tie", new ADisplayEntity("Hand {number}: Tie!", true, true));
    app.addMessageEntity("mes_id_info_game_result_player_left", new ADisplayEntity("Player {name} lose all his money and left us.", true, true));
    app.addMessageEntity("mes_id_info_shoe_is_reassembled", new ADisplayEntity("Shoe has been reassembled.", true, true));

    app.requestInputToCreatePlayer();

    app.startGame();
}

int main()
{
    initConsoleApplication();

    return 0;
}