#include "ConsoleDisplayHandler.h"

void ConsoleDisplayHandler::clearConsole()
{
    system("cls"); // For Windows OS only
}

void ConsoleDisplayHandler::display(ConsoleDisplayEntity* entity) const
{
    this->clearConsole();

    std::cout << entity->getDisplayEntity();

    if (entity->hasEndLine())
    {
        std::cout << std::endl;
    }
}

void ConsoleDisplayHandler::displayBatch(std::vector<ConsoleDisplayEntity*> entities) const
{
    this->clearConsole();

    for (auto const& entity: entities)
    {
        std::cout << entity->getDisplayEntity();

        if (entity->hasEndLine())
        {
            std::cout << std::endl;
        }
    }
}

//void ConsoleDisplayHandler::display(const AbstractDisplayEntity<std::string> &entity) const
//{
//    std::cout << entity.getDisplayEntity();
//}

//void ConsoleDisplayHandler::display(const ConsoleDisplayEntity &entity) const
////{
////    std::cout << entity.getDisplayEntity();
////}