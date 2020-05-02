#include "ConsoleDisplayHandler.h"

void ConsoleDisplayHandler::display(const AbstractDisplayEntity<std::string> &entity) const
{
    std::cout << entity.getDisplayEntity();
}

//void ConsoleDisplayHandler::display(const ConsoleDisplayEntity &entity) const
////{
////    std::cout << entity.getDisplayEntity();
////}