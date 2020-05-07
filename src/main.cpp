#include <iostream>
#include <string>

#include "Application.h"
#include "InputHandler.h"
#include "ConsoleInputAdapter.h"
#include "ConsoleDisplayHandler.h"
#include "ConsoleDisplayEntity.h"

void initConsoleApplication()
{
    Application<InputHandler, ConsoleInputAdapter, ConsoleDisplayHandler, ConsoleDisplayEntity> app;
    app.addMessageEntity("mes_id_info_player_enter_name", new ConsoleDisplayEntity("Enter player name:", false));
    app.addMessageEntity("mes_id_error_player_name_invalid", new ConsoleDisplayEntity("Player name is invalid."));
    app.createPlayer();

//    auto* app = new Application<InputHandler, ConsoleInputAdapter, ConsoleDisplayHandler, ConsoleDisplayEntity>();
//    app->createPlayer();
}

int main()
{
    initConsoleApplication();

    return 0;
}
