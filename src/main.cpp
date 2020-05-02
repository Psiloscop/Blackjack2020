#include <iostream>
#include <string>

#include "Card.h"
#include "ConsoleDisplayEntity.h"
#include "AbstractDisplayHandler.h"
#include "ConsoleDisplayHandler.h"
#include "ConsoleApplication.h"

int main()
{
//    Card* cardEx1 = new Card(2, CardSuit(1));
//    Card* cardEx2 = new Card(3, CardSuit(1));
//    *cardEx1 == *cardEx2;

//    std::string tmp = "Entity string";
//    ConsoleDisplayEntity entity(tmp);
//    ConsoleDisplayHandler handler;
//    handler.display(entity);

    Application* app = new ConsoleApplication<std::string>(new ConsoleDisplayHandler());

    return 0;
}
