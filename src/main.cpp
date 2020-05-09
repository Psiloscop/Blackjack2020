#include <iostream>
#include <string>
#include <conio.h>

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
    app.addMessageEntity("mes_id_info_player_enter_start_cash", new ConsoleDisplayEntity("Enter player's start cash:", false));
    app.addMessageEntity("mes_id_error_player_cash_invalid", new ConsoleDisplayEntity("Player's start cash must be non-negative integer value and less that 1000"));

    app.createPlayer();
}


int main()
{
    initConsoleApplication();

    return 0;
}









//#include <iostream>
//#include <algorithm>
//#include <windows.h>
//
//void clear_screen(char fill = ' ') {
//    COORD tl = {0,0};
//    CONSOLE_SCREEN_BUFFER_INFO s;
//    HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
//
//    GetConsoleScreenBufferInfo(console, &s);
//
//    DWORD written, cells = s.dwSize.X * s.dwSize.Y;
//
//    FillConsoleOutputCharacter(console, fill, cells, tl, &written);
//    FillConsoleOutputAttribute(console, s.wAttributes, cells, tl, &written);
//    SetConsoleCursorPosition(console, tl);
//}
//
//int main()
//{
//    std::cout << "test1" << std::endl;
////    std::cout << "test2";
////    std::cout << "test3";
//
////    std::string string;
////    std::getline(std::cin, string);
////    string.erase(remove(string.begin(), string.end(), '\n'), string.end());
//
//    clear_screen();
//
//    std::cout << "test2";
//
//    return 0;
//}