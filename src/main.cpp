#include <iostream>
#include <string>

#include "Card.h"
#include "ConsoleDisplayEntity.h"
#include "intDisplayEntity.h"
#include "ConsoleDisplayHandler.h"

int main()
{
//    Card* cardEx1 = new Card(2, CardSuit(1));
//    Card* cardEx2 = new Card(3, CardSuit(1));
//    *cardEx1 == *cardEx2;

    std::string tmp = "Entity string";
    ConsoleDisplayEntity entity(tmp);
    ConsoleDisplayHandler handler;
    handler.display(entity);

//    int tmp2 = 111;
//    IntDisplayEntity entity2(tmp2);
//    handler.display(entity2);

    return 0;
}
