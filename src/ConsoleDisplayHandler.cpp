#include "ConsoleDisplayHandler.h"
#include "AppTypes.h"

void ConsoleDisplayHandler::clearConsole() const
{
#if defined(_WIN32) || defined(_WIN64)
    system("cls");
#else
    system("clear");
#endif
}

void ConsoleDisplayHandler::display(ConsoleDisplayEntity* entity, std::map<std::string, std::string> params) const
{
    this->clearConsole();

    std::string cache = this->processText(entity->getDisplayEntity(), params);

    if (entity->hasEndLine())
    {
        cache += "\n";
    }

    std::cout << cache << std::flush;
}

void ConsoleDisplayHandler::displayBatch(std::vector<ConsoleDisplayEntity*> entities, std::vector<std::map<std::string, std::string>> params) const
{
    this->clearConsole();

    std::string cache;
    u8 index = 0;

    for (auto const& entity: entities)
    {
        cache += this->processText(entity->getDisplayEntity(), params[index++]);

        if (entity->hasEndLine())
        {
            cache += "\n";
        }
    }

    std::cout << cache << std::flush;
}