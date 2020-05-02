#include <iostream>

#include "Card.h"

int main()
{
    Card* cardEx1 = new Card(2, CardSuit(1));
    Card* cardEx2 = new Card(3, CardSuit(1));

    *cardEx1 == *cardEx2;

    return 0;
}
