#include "ConsoleDisplayHandler.h"

void ConsoleDisplayHandler::clearConsole() const
{
//    std::cout << std::string(50, '\n');
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