#ifndef GAME_H
#define GAME_H
#include "pawn.h"
#include <vector>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cmath>

using namespace std;
enum warc {s,a,b,c,d,e,f,g,h}; //enum dla latwiejszego wpisywania wybranego pol

class game
{
public:
    vector <pawn> board; // kontyner na pioneki
    pawn tab[9][9];           // tablica ulatwiajaca wypisywanie pola gra
    string czarny,bialy;      // gracze
    bool fight,conti;         // zmienne boolowskie decydujace o biciu i sprawdzajace czy moze zostac wykonane nastepne bicie


    game();                   //ustawiam nim pionki w pozycje poczatkowa

public:
    void show();                                //funkcja organizuaca gre
    void toArray();                             //funkcja wypisuje obecna gre w konsoli
    bool choiceCheck(warc ,int,string);          //funkcja sprawdzajaca wybor pionka ze zwrotnymi komentarzami
    bool choiceCheckComp(int,int,string);       //funkcja sprawdzajaca wybor pionka bez zwrotnych komentarzow
    bool moveCheck(int,int,int,int,string);     //funkcja sprawdzajaca ruch dla wybranego pionka ze zwrotnymi komentarzami
    bool moveCheckComp(int,int,int,int,string); //funkcja sprawdzajaca ruch dla wybranego pionka bez zwrotnych komentarzow
    void move(int,int,int,int,string);          //funkcja wykonujaca ruch pionka
    void test();                                //funkcja sluzy do testowania innych ustawien pionkow
    vector<pawn> makeListChoice(string);        //funkcja tworzaca liste dostepnych pionkow
    vector<pawn> makeListMove(pawn pion,string);        //funckja tworzaca liste ruchow dla danego pionka
    bool continueMove(int,int,string);          //funkcja sprawdzajaca czy nastapilo bicie jesli tak to pozwala bic dalej
    bool win();                                 //funkcja sprawdza czy nastapila wygrana ktoregos z graczy
    void dame(string);                          //funkcja sprawdza czy po ruchu zamienic pionek w dame
    bool checkI(int x,int y,string aktualny);
    bool checkII(int x,int y,int x2,int y2,string aktualny);
};


#endif // GAME_H
