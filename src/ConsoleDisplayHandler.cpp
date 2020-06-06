#include "ConsoleDisplayHandler.h"
#include "AppAliasDisplayMessageParam.h"
#include "AppTypes.h"

#if defined(_WIN32) || defined(_WIN64)
#include <windows.h>
#endif

ConsoleDisplayHandler::ConsoleDisplayHandler()
{
#if defined(_WIN32) || defined(_WIN64)
    SetConsoleOutputCP(CP_UTF8);
#endif
}

void ConsoleDisplayHandler::clearConsole() const
{
#if defined(_WIN32) || defined(_WIN64)
    system("cls");
#else
    system("clear");
#endif
}

void ConsoleDisplayHandler::display(ConsoleDisplayEntity* entity, std::vector<ADisplayMessageParam*> params) const
{
    this->clearConsole();

    std::string cache = this->processText(entity->getDisplayEntity(), params);

    if (entity->hasEndLine())
    {
        cache += "\n";
    }

    std::cout << cache << std::flush;
}

void ConsoleDisplayHandler::displayBatch(std::vector<ConsoleDisplayEntity*> entities, std::vector<std::vector<ADisplayMessageParam*>> params) const
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

void ConsoleDisplayHandler::transformCardListEntity(ADisplayMessageParam* entity, std::vector<Card*>& cards)
{
    std::string strCards;

    for (auto card : cards)
    {
        strCards += card->getCardLetter();

        switch (card->getCardSuit())
        {
            case spade:
                strCards += "♠"; // L"\u2660"
                break;

            case club:
                strCards += "♣"; // L"\u2663"
                break;

            case heart:
                strCards += "♥"; // "L"\u2665"
                break;

            case diamond:
                strCards += "♦"; // L"\u2666"
                break;
        }

        strCards += " ";
    }

    entity->setValue(strCards);
}