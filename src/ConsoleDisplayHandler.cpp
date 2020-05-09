#include "ConsoleDisplayHandler.h"

void ConsoleDisplayHandler::clearConsole() const
{
#if defined(_WIN32) || defined(_WIN64)
    system("cls");
#else
    system("clear");
#endif
}

void ConsoleDisplayHandler::display(ConsoleDisplayEntity* entity) const
{
    this->clearConsole();

    std::string cache = entity->getDisplayEntity();

    if (entity->hasEndLine())
    {
        cache += "\n";
    }

    std::cout << cache << std::flush;
}

void ConsoleDisplayHandler::displayBatch(std::vector<ConsoleDisplayEntity*> entities) const
{
    this->clearConsole();

    std::string cache;

    for (auto const& entity: entities)
    {
        cache += entity->getDisplayEntity();

        if (entity->hasEndLine())
        {
            cache += "\n";
        }
    }

    std::cout << cache << std::flush;
}