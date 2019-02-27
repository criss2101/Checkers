#ifndef NODE_H
#define NODE_H
#include <list>
#include "game.h"

class node
{
    public:
    pawn pawnn;        //tu zapisuje ruch
    game giera;        //sytuacja na planszy po nowym ruchu
    int wynik;              //maksymalna wartosc dla danej sytuacji
    node(game gra);


};

#endif // NODE_H
