#include <iostream>
#include <string>

#include "Application.h"
#include "InputHandler.h"
#include "ConsoleInputAdapter.h"
#include "ConsoleDisplayHandler.h"
#include "ConsoleDisplayEntity.h"
//#include "PlayerStartCashInputValidator.h"

//using TApplication = Application<InputHandler, ConsoleInputAdapter, ConsoleDisplayHandler, ConsoleDisplayEntity>;

void initConsoleApplication()
{
    Application<InputHandler, ConsoleInputAdapter, ConsoleDisplayHandler, ConsoleDisplayEntity> app;
//    TApplication app;

    app.addMessageEntity("mes_id_info_player_enter_name", new ConsoleDisplayEntity("Enter player name:", false));
    app.addMessageEntity("mes_id_error_player_name_invalid", new ConsoleDisplayEntity("Player name is invalid."));
    app.addMessageEntity("mes_id_info_player_enter_start_cash", new ConsoleDisplayEntity("Enter player's start cash:", false));
    app.addMessageEntity("mes_id_error_player_cash_invalid", new ConsoleDisplayEntity("Player's start cash must be non-negative integer value and less that 1000"));

    app.requestInputToCreatePlayer();
}

int main()
{
    initConsoleApplication();

    return 0;
}