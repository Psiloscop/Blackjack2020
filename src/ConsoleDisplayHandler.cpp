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

void ConsoleDisplayHandler::transformCardListEntity(ConsoleDisplayEntity* entity, std::vector<Card*> cards)
{
    std::string strCards = "";

    for (auto card : cards)
    {
        strCards += card->getCardLetter();

        switch (card->getCardSuit())
        {
            case CardSuit::spade:
                strCards += "♠"; // L"\u2660"

            case CardSuit::club:
                strCards += "♣"; // L"\u2663"

            case CardSuit::heart:
                strCards += "♥"; // "L"\u2665"

            case CardSuit::diamond:
                strCards += "♦"; // L"\u2666"
        }

        strCards += " ";
    }

    std::map<std::string, std::string> messageParamList;
    messageParamList.insert({
        std::pair<std::string, std::string>("cards", strCards),
    });

//    entity->setDisplayEntity(this->processText(entity->getDisplayEntity(), messageParamList));
    this->processText(entity->getDisplayEntity(), messageParamList);
}
