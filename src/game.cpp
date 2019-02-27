#include "game.h"
using namespace std;


ostream& operator <<(ostream& wyj,warc Arg)
{
    const char* tabZnakow= "sabcdefgh";
    wyj<<tabZnakow[Arg];

    return wyj;
}


istream& operator >>(istream& wej,warc& Arg)
{
    warc tabSymboli[]= {s,a,b,c,d,e,f,g,h};
    char* ptrSymbol;
    const char* tabZnakow= "sabcdefgh";
    char tmpZnak= 'x';
    wej>>tmpZnak;

    if(ptrSymbol= (char*)strchr(tabZnakow, tmpZnak))
    {
        Arg=tabSymboli[ptrSymbol-tabZnakow];
    }

    return wej;
}


warc operator--(warc &Arg)
{
    warc tab[]= {h,a,b,c,d,e,f,g,h};
    int x=Arg;
    x--;
    Arg=tab[x];

    return Arg;
}


warc operator++(warc &Arg)
{
    warc tab[]= {h,a,b,c,d,e,f,g,h};
    int x=Arg;
    x++;
    Arg=tab[x];

    return Arg;
}


game::game()
{


    czarny="czerwony";
    bialy="zielony";

    fight=false;
    conti=false;
    board.push_back(pawn(a,8,'p'));
    board.push_back(pawn(b,8,'b'));
    board.push_back(pawn(c,8,'p'));
    board.push_back(pawn(d,8,'b'));
    board.push_back(pawn(e,8,'p'));
    board.push_back(pawn(f,8,'b'));
    board.push_back(pawn(g,8,'p'));
    board.push_back(pawn(h,8,'b'));

    board.push_back(pawn(a,7,'b'));
    board.push_back(pawn(b,7,'p'));
    board.push_back(pawn(c,7,'b'));
    board.push_back(pawn(d,7,'p'));
    board.push_back(pawn(e,7,'b'));
    board.push_back(pawn(f,7,'p'));
    board.push_back(pawn(g,7,'b'));
    board.push_back(pawn(h,7,'p'));

    board.push_back(pawn(a,6,'p'));
    board.push_back(pawn(b,6,'b'));
    board.push_back(pawn(c,6,'p'));
    board.push_back(pawn(d,6,'b'));
    board.push_back(pawn(e,6,'p'));
    board.push_back(pawn(f,6,'b'));
    board.push_back(pawn(g,6,'p'));
    board.push_back(pawn(h,6,'b'));

//SRODEK
    board.push_back(pawn(a,5,'d'));
    board.push_back(pawn(b,5,'p'));
    board.push_back(pawn(c,5,'d'));
    board.push_back(pawn(d,5,'p'));
    board.push_back(pawn(e,5,'d'));
    board.push_back(pawn(f,5,'p'));
    board.push_back(pawn(g,5,'d'));
    board.push_back(pawn(h,5,'p'));

//SRODEK
    board.push_back(pawn(a,4,'p'));
    board.push_back(pawn(b,4,'d'));
    board.push_back(pawn(c,4,'p'));
    board.push_back(pawn(d,4,'d'));
    board.push_back(pawn(e,4,'p'));
    board.push_back(pawn(f,4,'d'));
    board.push_back(pawn(g,4,'p'));
    board.push_back(pawn(h,4,'d'));

//CZARNE
    board.push_back(pawn(a,3,'c'));
    board.push_back(pawn(b,3,'p'));
    board.push_back(pawn(c,3,'c'));
    board.push_back(pawn(d,3,'p'));
    board.push_back(pawn(e,3,'c'));
    board.push_back(pawn(f,3,'p'));
    board.push_back(pawn(g,3,'c'));
    board.push_back(pawn(h,3,'p'));

    board.push_back(pawn(a,2,'p'));
    board.push_back(pawn(b,2,'c'));
    board.push_back(pawn(c,2,'p'));
    board.push_back(pawn(d,2,'c'));
    board.push_back(pawn(e,2,'p'));
    board.push_back(pawn(f,2,'c'));
    board.push_back(pawn(g,2,'p'));
    board.push_back(pawn(h,2,'c'));


    board.push_back(pawn(a,1,'c'));
    board.push_back(pawn(b,1,'p'));
    board.push_back(pawn(c,1,'c'));
    board.push_back(pawn(d,1,'p'));
    board.push_back(pawn(e,1,'c'));
    board.push_back(pawn(f,1,'p'));
    board.push_back(pawn(g,1,'c'));
    board.push_back(pawn(h,1,'p'));
    board.push_back(pawn(0,0,'o'));
    test();
}


void game::toArray()
{
    string green = "\033[92m";
    string  normal = "\033[97m";
    string yellow = "\033[93m";
    string red = "\033[91m";
    string grey = "\033[90m";
    int k=0,l=7;

    while(board[k].colour!='o')
    {
        tab[board[k].y][board[k].x]=board[k];
        k++;
    }

    system("clear");

    cout<<normal<<"    _______________"<<endl<<" 8 |";
    for(int i=8; i>0; i--)
    {
        for(int j=1; j<9; j++)
        {
            if(j==8)
            {

                if(tab[i][j].colour=='d')
                    cout<<yellow<<"◦"<<normal<<"|"<<endl;
                else if(tab[i][j].colour=='c')
                    cout<<red<<"♟"<<normal<<"|"<<endl;
                else if(tab[i][j].colour=='b')
                    cout<<green<<"♟"<<normal<<"|"<<endl;
                else if(tab[i][j].colour=='u')
                    cout<<green<<"♛"<<normal<<"|"<<endl;
                else if(tab[i][j].colour=='q')
                    cout<<red<<"♛"<<normal<<"|"<<endl;
                else if(tab[i][j].colour=='p')
                    cout<<grey<<"✳"<<normal<<"|"<<endl;

                if(l!=0)
                    cout<<" "<<l--<<" |";
            }
            else
            {
                if(tab[i][j].colour=='d')
                    cout<<yellow<<"◦"<<normal<<"|";
                else if(tab[i][j].colour=='c')
                    cout<<red<<"♟"<<normal<<"|";
                else if(tab[i][j].colour=='b')
                    cout<<green<<"♟"<<normal<<"|";
                else if(tab[i][j].colour=='u')
                    cout<<green<<"♛"<<normal<<"|";
                else if(tab[i][j].colour=='q')
                    cout<<red<<"♛"<<normal<<"|";
                else if(tab[i][j].colour=='p')
                    cout<<grey<<"✳"<<normal<<"|";
            }
        }
    }
    cout<<"    ---------------"<<endl;
    cout<<"    a b c d e f g h ";
    cout<<endl<<endl;
}


vector<pawn> game::makeListChoice(string aktualny)
{
    vector<pawn> listChoice;
    vector<pawn> listFight;
    int k=0;

    while(board[k++].colour!='o')
    {
//lista dla pionkow ktore moga wykonac ruch
        if(choiceCheckComp(board[k].x,board[k].y,aktualny))
        {
            if(board[k].colour=='c' && (moveCheckComp(board[k].x, board[k].y, board[k].x+1, board[k].y+1, aktualny) || moveCheckComp(board[k].x, board[k].y, board[k].x-1, board[k].y+1, aktualny)))
                listChoice.push_back(board[k]);

            else if(board[k].colour=='b' && (moveCheckComp(board[k].x, board[k].y, board[k].x+1, board[k].y-1, aktualny) || moveCheckComp(board[k].x, board[k].y, board[k].x-1, board[k].y-1, aktualny)))
                listChoice.push_back(board[k]);

            if(board[k].colour=='c' && (moveCheckComp(board[k].x, board[k].y, board[k].x+2, board[k].y+2, aktualny) || moveCheckComp(board[k].x, board[k].y, board[k].x-2, board[k].y+2, aktualny)))
                listFight.push_back(board[k]);

            else if(board[k].colour=='b' && (moveCheckComp(board[k].x, board[k].y, board[k].x+2, board[k].y-2, aktualny) || moveCheckComp(board[k].x, board[k].y, board[k].x-2, board[k].y-2, aktualny)))
                listFight.push_back(board[k]);

            else if((board[k].colour=='q' || board[k].colour=='u') && (moveCheckComp(board[k].x, board[k].y, board[k].x+1, board[k].y+1, aktualny) || moveCheckComp(board[k].x, board[k].y, board[k].x-1, board[k].y+1, aktualny) ||
                    moveCheckComp(board[k].x, board[k].y, board[k].x+1, board[k].y-1, aktualny) || moveCheckComp(board[k].x, board[k].y, board[k].x-1, board[k].y-1, aktualny)
                    ||
                    moveCheckComp(board[k].x, board[k].y, board[k].x+2, board[k].y+2, aktualny) || moveCheckComp(board[k].x, board[k].y, board[k].x-2, board[k].y+2, aktualny) ||
                    moveCheckComp(board[k].x, board[k].y, board[k].x+2, board[k].y-2, aktualny) || moveCheckComp(board[k].x, board[k].y, board[k].x-2, board[k].y-2, aktualny)))
            {
                listChoice.push_back(board[k]);
            }

        }
    }
    /*odkomentowane wyswietli te liste

    if(listFight.empty()){
        for(int i=0; i<listChoice.size(); i++)
        {
            cout<<"   "<<"Ruchy dla "<<listChoice[i].x<<listChoice[i].y<<": ";
            makeListMove(listChoice[i],aktualny);

        }
        }
    else{
     for(int i=0; i<listFight.size(); i++)
        {
            cout<<"   "<<"Ruchy dla "<<listFight[i].x<<listFight[i].y<<": ";
            makeListMove(listFight[i],aktualny);

        }
    }*/

    if(listFight.empty())
        return listChoice;
    else
        return listFight;


}

bool game::checkI(int x,int y,string aktualny){
vector <pawn> listChoice;
listChoice=makeListChoice(aktualny);

for(int i=0;i<listChoice.size();i++){
if(listChoice[i].x==x && listChoice[i].y==y){
return true;
}
}

cout<<"Nie mozesz wybrac tego pionka !"<<endl;
return false;
}

bool game::checkII(int x,int y,int x2,int y2,string aktualny){
vector <pawn> listChoice;
vector <pawn> listMove;
listChoice=makeListChoice(aktualny);

for(int i=0;i<listChoice.size();i++){
if(listChoice[i].x==x && listChoice[i].y==y){
listMove=makeListMove(listChoice[i],aktualny);
break;
}
}


for(int j=0;j<listMove.size();j++){
if(listMove[j].x==x2 && listMove[j].y==y2){
return true;
}
}


cout<<"Nie mozesz wykonac tego ruchu !"<<endl;
return false;
}






vector<pawn> game::makeListMove(pawn pion,string aktualny)
{
    vector<pawn> listMove;
    vector<pawn> listFight;
    int k=0;

    while(board[k++].colour!='o')
    {

        if(moveCheckComp(pion.x,pion.y,board[k].x,board[k].y,aktualny))
            if(abs(board[k].x-pion.x)==2)
                listFight.push_back(board[k]);
    }

    k=0;

    if(listFight.empty())
    {

        while(board[k++].colour!='o')
        {
            if(moveCheckComp(pion.x,pion.y,board[k].x,board[k].y,aktualny))
                listMove.push_back(board[k]);
        }


    }
    /*odkomentowane wyswietli ta liste
        if(!listFight.empty())
            for(int l=0; l<listFight.size(); l++)
                cout<<listFight[l].x<<listFight[l].y<<" ";
    else
            for(int l=0; l<listMove.size(); l++)
                cout<<listMove[l].x<<listMove[l].y<<" ";
        cout<<endl;*/

    if(listFight.empty())
        return listMove;
    else
        return listFight;
}


bool game::choiceCheck(warc x,int y,string aktualny)
{

    int k=0;
    while(board[k++].colour!='o')
    {
        if(board[k].x==x && board[k].y==y)
        {
            if(board[k].colour=='d')
            {
                cout<<endl<<"Tu nie ma pionka, wybierz jeszcze raz !"<<endl;
                return false;
            }
            else if(board[k].colour=='c' && aktualny==bialy)
            {
                cout<<endl<<"Tu nie Twoje pionki, wybierz jeszcze raz !"<<endl;
                return false;
            }
            else if(board[k].colour=='b' && aktualny==czarny)
            {
                cout<<endl<<"To nie Twoje pionki, wybierz jeszcze raz !"<<endl;
                return false;
            }
            else if(board[k].colour=='q' && aktualny==bialy)
            {
                cout<<endl<<"To nie Twoje pionki, wybierz jeszcze raz !"<<endl;
                return false;
            }
            else if(board[k].colour=='u' && aktualny==czarny)
            {
                cout<<endl<<"To nie Twoje pionki, wybierz jeszcze raz !"<<endl;
                return false;
            }
            else if(board[k].colour=='p' )
            {
                cout<<endl<<"Tu nie ma pionka, wybierz jeszcze raz !"<<endl;
                return false;
            }
            else
                return true; //Wybrano pionek poprawnie
        }
    }
    return true;
}


bool game::moveCheck(int x,int y,int x2,int y2,string aktualny)
{
    int helpX=x2;
    int helpY=y2;
    bool murder=false;
    bool dama=false;
    int temp;
    int k=0; // SPRAWDZA CZY POLE PUSTE

    while(board[k++].colour!='o')
    {
        if(board[k].x==x2 && board[k].y==y2)
        {
            if(board[k].colour!='d')
            {
                cout<<endl<<"To pole jest zajęte, wybierz pole jeszcze raz !"<<endl;
                return false;
            }
        }
    }


    int d=0;
    while(board[d++].colour!='o')  // SPRAWDZA CZY PIONEK JEST DAMA
    {
        if(board[d].x==x && board[d].y==y)
        {
            if(board[d].colour=='q' || board[d].colour=='u')
            {
                dama=true;
            }
        }
    }


    if( (abs(y2-y) > 2 || abs(x2-x) > 2) && dama==false ) // ZALOZENIA DLA PIONKOW
    {
        cout<<endl<<"Ruch niedozwolony, wybierz pole jeszcze raz !"<<endl;
        return false;
    }



    if( (abs(y2-y)==1 || y2==y) && dama==false)   // RUCH O JEDEN y2==y wpuszczam ale potem to wylapuje
    {
        if(aktualny==czarny && ((abs(x2-x)!=1) || (y2!=y+1)  ))
        {
            cout<<endl<<"Ruch niedozwolony, wybierz pole jeszcze raz !"<<endl;
            return false;
        }
        if(aktualny==bialy && ((abs(x2-x)!=1) || (y2!=y-1)  ))
        {
            cout<<endl<<"Ruch niedozwolony, wybierz pole jeszcze raz !"<<endl;
            return false;
        }
        if(conti)  // JESLI JESTEM W STANIE BICIA TO RUCH PO BICIU NIE MOZE BYC O JEDEN
        {

            if((x2-x)<2)
            {
                cout<<endl<<"Ruch niedozwolony, wybierz pole jeszcze raz !"<<endl;
                return false;
            }
        }
    }



    if( abs(y2-y)==2 && dama==false )  //RUCH O DWA CZYLI SPRAWDZAMY BICIE PIONKOW
    {
        /*SZUKAM POLA POMIEDZY */
        k=0;
        while(board[k++].colour!='o') //
        {
            if(aktualny==czarny && x2>x)  // RUCH CZARNEGO SPRAWDZAMY CO JEST NA JEGO DRODZE
            {
                if(board[k].x==x2-1 && board[k].y==y2-1 )
                {

                    if(board[k].colour=='b' || board[k].colour=='u')
                    {
                        murder=true;
                        break;
                    }
                    else if(board[k].colour=='d' || board[k].colour=='c'|| board[k].colour=='q' ) // PRZEZ TAKIE PIONKI NIE SKACZEMY
                    {
                        cout<<endl<<"Ruch niedozwolony, wybierz pole jeszcze raz !"<<endl;
                        return false;

                    }


                }
            }
            else if(aktualny==czarny && x2<x) // W LEWO CZARNY
            {
                if(board[k].x==x2+1 && board[k].y==y2-1 )
                {
                    if(board[k].colour=='b' || board[k].colour=='u')
                    {
                        murder=true;
                        break;
                    }
                    else if(board[k].colour=='d'|| board[k].colour=='c' || board[k].colour=='q')
                    {
                        cout<<endl<<"Ruch niedozwolony, wybierz pole jeszcze raz !"<<endl;
                        return false;

                    }


                }
            }


            if(aktualny==bialy && x2>x)  // RUCH BIALEGO SPRAWDZAMY CO JEST NA JEGO DRODZE
            {
                if(board[k].x==x2-1 && board[k].y==y2+1 )
                {
                    if(board[k].colour=='c' || board[k].colour=='q') // TU NASTEPUJE BICIE
                    {
                        murder=true;
                        break;
                    }
                    else if(board[k].colour=='d' || board[k].colour=='b' || board[k].colour=='u')
                    {
                        cout<<endl<<"Ruch niedozwolony, wybierz pole jeszcze raz !"<<endl;
                        return false;
                    }
                }
            }
            else if(aktualny==bialy && x2<x )
            {
                if(board[k].x==x2+1 && board[k].y==y2+1 )
                {
                    if(board[k].colour=='c' || board[k].colour=='q') // TU NASTEPUJE BICIE
                    {
                        murder=true;
                        break;
                    }
                    else if(board[k].colour=='d' || board[k].colour=='b' || board[k].colour=='u')
                    {
                        cout<<endl<<"Ruch niedozwolony, wybierz pole jeszcze raz !"<<endl;
                        return false;
                    }
                }
            }
        }


        if(aktualny==czarny && ((abs(x2-x)!=2) || (y2!=y+2)) )
        {
            cout<<endl<<"Ruch niedozwolony, wybierz pole jeszcze raz !"<<endl;
            return false;
        }
        if(aktualny==bialy && ((abs(x2-x)!=2) || (y2!=y-2)) )
        {
            cout<<endl<<"Ruch niedozwolony, wybierz pole jeszcze raz !"<<endl;
            return false;
        }

        if(murder)
        {
            board[k].dead();
            fight=true;
        }

    } /* KONIEC SPRAWDZANIA RUCHU O DWA */

    /* DAMA */
    if(dama)
    {
        if( abs(x2-x)!=abs(y2-y) )
        {
            cout<<endl<<"Ruch niedozwolony, wybierz pole jeszcze raz !"<<endl;
            return false;
        }


        /* BICIE DAMKI */
        int n=0;
        int l=0;
        int lc=0;
        k=0;

        while(board[k++].colour!='o')
        {
            if(aktualny==czarny) // DROGA CZARNEGO
            {
                if(board[k].x==x2 && board[k].y==y2) //SPRAWDZANIE DROGI DO CELU
                {

                    while(x2!=x && y2!=y)
                    {

                        while(board[n++].colour!='o')
                        {
                            if(board[n].x==x2 && board[n].y==y2 && (board[n].colour=='c' || board[n].colour=='q') )
                            {
                                cout<<endl<<"Ruch niedozwolony, wybierz pole jeszcze raz !"<<endl;
                                return false;
                            }
                            else if(board[n].x==x2 && board[n].y==y2 && (board[n].colour=='b' || board[n].colour=='u'))
                            {
                                temp=n;
                                l++;
                                if(l>1)
                                {
                                    cout<<endl<<"Ruch niedozwolony, wybierz pole jeszcze raz !"<<endl;
                                    return false;
                                }
                            }

                        }


                        if(x2>x && y2>y) // PRAWA GORA
                        {
                            --x2;
                            --y2;
                        }
                        else if(x2<x && y2>y) //LEWA GORA
                        {
                            ++x2;
                            --y2;
                        }
                        else if(x2>x && y2<y) //PRAWA DOL
                        {
                            --x2;
                            ++y2;
                        }
                        else if(x2<x && y2<y) //LEWA DOL
                        {
                            ++x2;
                            ++y2;
                        }
                        n=0;
                    }
                    if(l==1)
                    {
                        murder=true;
                    }
                    if(!conti)
                        break;
                }
            }


            n=0;
            if(aktualny==bialy) // DROGA BIALEGO
            {
                if(board[k].x==x2 && board[k].y==y2) //SPRAWDZANIE DROGI DO CELU
                {

                    while(x2!=x && y2!=y)
                    {

                        while(board[n++].colour!='o')
                        {
                            if(board[n].x==x2 && board[n].y==y2 && (board[n].colour=='b' || board[n].colour=='u') )
                            {
                                cout<<endl<<"Ruch niedozwolony, wybierz pole jeszcze raz !"<<endl;
                                return false;
                            }
                            else if(board[n].x==x2 && board[n].y==y2 && (board[n].colour=='c' || board[n].colour=='q'))
                            {
                                temp=n;
                                l++;
                                if(l>1)
                                {
                                    cout<<endl<<"Ruch niedozwolony, wybierz pole jeszcze raz !"<<endl;
                                    return false;
                                }
                            }

                        }


                        if(x2>x && y2>y) // PRAWA GORA
                        {
                            --x2;
                            --y2;
                        }
                        else if(x2<x && y2>y) //LEWA GORA
                        {
                            ++x2;
                            --y2;
                        }
                        else if(x2>x && y2<y) //PRAWA DOL
                        {
                            --x2;
                            ++y2;
                        }
                        else if(x2<x && y2<y) //LEWA DOL
                        {
                            ++x2;
                            ++y2;
                        }
                        n=0;
                    }
                    if(l==1)
                    {
                        murder=true;
                    }
                    if(!conti)
                        break;
                }
            }

            n=0;
            if(conti) // W PRZYPADKU BICIA NASTEPNY RUCH O ILE ISTNIEJE MUSI BIC POMOC DLA FUNKCJI CONTINUE
            {
                if(abs(helpX-x)==1)  // PO BICIU POJEDYNCZY KROK NIE JEST MOZLIWY
                {
                    cout<<endl<<"Ruch niedozwolony, wybierz pole jeszcze raz !"<<endl;
                    return false;
                }

                if(board[k].x==helpX && board[k].y==helpY) //SPRAWDZANIE DROGI DO CELU
                {


                    while(helpX!=x && helpY!=y)
                    {

                        while(board[n++].colour!='o')
                        {
                            if(board[n].x==helpX && board[n].y==helpY && (board[n].colour=='b' || board[n].colour=='u' || (board[n].colour=='c' || board[n].colour=='q')))
                            {
                                lc++;

                            }

                        }


                        if(helpX>x && helpY>y) // PRAWA GORA
                        {
                            --helpX;
                            --helpY;
                        }
                        else if(helpX<x && helpY>y) //LEWA GORA
                        {
                            ++helpX;
                            --helpY;
                        }
                        else if(helpX>x && helpY<y) //PRAWA DOL
                        {
                            --helpX;
                            ++helpY;
                        }
                        else if(helpX<x && helpY<y) //LEWA DOL
                        {
                            ++helpX;
                            ++helpY;
                        }
                        n=0;
                    }

                    if( lc!=1 )
                    {
                        cout<<endl<<"Ruch niedozwolony, wybierz pole jeszcze raz !"<<endl;
                        return false;
                    }

                    break;
                }
            }

        } //KONIEC WHILE

        if(murder)
        {
            board[temp].dead();
            fight=true;
        }
    }

    return true;
}


void game::move(int x,int y,int x2,int y2,string aktualny)
{
    bool blackQueen=false;
    bool whiteQueen=false;
    int k=0;
    while(board[k++].colour!='o')
    {
        if(board[k].x==x && board[k].y==y)
        {
            if(board[k].colour=='q')
                blackQueen=true;
            else if(board[k].colour=='u')
                whiteQueen=true;

            board[k].colour='d';
        }
    }

    k=0;
    while(board[k++].colour!='o')
    {
        if(board[k].x==x2 && board[k].y==y2)
        {
            if(aktualny==czarny && blackQueen)
            {
                board[k].colour='q';
                break;
            }
            else if(aktualny==bialy && whiteQueen)
            {
                board[k].colour='u';
                break;
            }
            else if(aktualny==czarny)
            {
                board[k].colour='c';

            }
            else if(aktualny==bialy)
            {
                board[k].colour='b';

            }

        }
    }

}


void game::dame(string aktualny)
{
    int k=0;

    if(aktualny==czarny)
    {
        while(board[k++].colour!='o')
        {
            if(board[k].y==8 && board[k].colour=='c')
            {
                board[k].colour='q';
                fight=false;
            }
        }
    }

    if(aktualny==bialy)
    {
        while(board[k++].colour!='o')
        {
            if(board[k].y==1 && board[k].colour=='b')
            {
                board[k].colour='u';
                fight=false;
            }
        }
    }
}


/*SPRAWDZAM CZY NASTAPILO BICIE JESLI TAK SPRAWDZAM CZY JEST MOZLIWOSC KONTYNUOWANIA BICIA*/
bool game::continueMove(int x,int y,string aktualny)
{
    int k=0;
    int l1=0,l2=0,l3=0,l4=0; // SPRAWDZAM ILOSC WYSTAPIEN
    int helpX=x+1;
    int helpY=y+1;
    int helpX_2;
    int helpY_2;
    if(fight)
    {
        while(board[k++].colour!='o') //SZUKAM INFORMACJI O DANYM PIONKU
        {
            if(board[k].x==x && board[k].y==y)
                break;
        }

        if(board[k].colour=='c')
        {
            if((moveCheckComp(x,y,x+2,y+2,aktualny)  || moveCheckComp(x,y,x-2,y+2,aktualny)))
            {
                conti=true;
                return true;
            }
        }

        if(board[k].colour=='b')
        {
            if(moveCheckComp(x,y,x+2,y-2,aktualny) || moveCheckComp(x,y,x-2,y-2,aktualny))
            {
                conti=true;
                return true;
            }
        }

        if(board[k].colour=='q' || board[k].colour=='u') // KONTYNUACJA DAMA
        {

            while(helpX<9 && helpY<9) //BICIE PRAWO GORA
            {
                if(moveCheckComp(x,y,helpX,helpY,aktualny))  //SPRAWDZAM CZY RUCH WGL MOZLIWY
                {
                    helpX_2=helpX;
                    helpY_2=helpY;
                    while(helpX_2!=x && helpY_2!=y)            //COFAM SIE I JESLI NA WCZESNIEJSZYCH POLACH BYLBY PUSTE POLA TO FALSE BICIE NIE BEDZIE KONTUNUOWANE
                    {
                        k=0;
                        while(board[k++].colour!='o')                        //SZUKAM W TABLICY DANEGO POLA I SPRAWDZAM CO W NIM JEST
                        {
                            if(board[k].x==helpX_2 && board[k].y==helpY_2)
                            {
                                if(board[k].colour=='c' || board[k].colour=='q' || board[k].colour=='b' || board[k].colour=='u' )
                                {
                                    l1++;
                                    break;
                                }
                            }

                        }
                        helpX_2--;
                        helpY_2--;
                        if(l1>0)                // JESLI NA DRODZE JEST COS DO BICIA KONTYNUUJ RUCH
                        {
                            conti=true;
                            return true;
                        }

                    }
                    helpX++;
                    helpY++;
                }


                helpX=x;
                helpX_2=helpX;
                helpY=y;
                helpY_2=helpY;
                while(helpX>0 && helpY<9) //BICIE LEWO GORA
                {
                    if(moveCheckComp(x,y,helpX,helpY,aktualny))  //SPRAWDZAM CZY RUCH WGL MOZLIWY
                    {
                        helpX_2=helpX;
                        helpY_2=helpY;

                        while(helpX_2!=x && helpY_2!=y)            //COFAM SIE I JESLI NA WCZESNIEJSZYCH POLACH BYLBY PUSTE POLA TO FALSE BICIE NIE BEDZIE KONTUNUOWANE
                        {
                            k=0;
                            while(board[k++].colour!='o')                        //SZUKAM W TABLICY DANEGO POLA I SPRAWDZAM CO W NIM JEST
                            {
                                if(board[k].x==helpX_2 && board[k].y==helpY_2)
                                {
                                    if(board[k].colour=='c' || board[k].colour=='q' || board[k].colour=='b' || board[k].colour=='u' )
                                    {
                                        l2++;
                                        break;
                                    }
                                }

                            }
                            helpX_2++;
                            helpY_2--;
                            if(l2>0)                // JESLI NA DRODZE JEST COS DO BICIA KONTYNUUJ RUCH
                            {
                                conti=true;
                                return true;
                            }
                        }

                    }
                    helpX--;
                    helpY++;
                }


                helpX=x;
                helpX_2=helpX;
                helpY=y;
                helpY_2=helpY;
                while(helpX<9 && helpY>0) //BICIE PRAWO DOL
                {
                    if(moveCheckComp(x,y,helpX,helpY,aktualny))  //SPRAWDZAM CZY RUCH WGL MOZLIWY
                    {
                        helpX_2=helpX;
                        helpY_2=helpY;

                        while(helpX_2!=x && helpY_2!=y)            //COFAM SIE I JESLI NA WCZESNIEJSZYCH POLACH BYLBY PUSTE POLA TO FALSE BICIE NIE BEDZIE KONTUNUOWANE
                        {
                            k=0;
                            while(board[k++].colour!='o')                        //SZUKAM W TABLICY DANEGO POLA I SPRAWDZAM CO W NIM JEST
                            {
                                if(board[k].x==helpX_2 && board[k].y==helpY_2)
                                {
                                    if(board[k].colour=='c' || board[k].colour=='q' || board[k].colour=='b' || board[k].colour=='u' )
                                    {
                                        l3++;
                                        break;
                                    }
                                }

                            }
                            helpX_2--;
                            helpY_2++;
                            if(l3>0)                // JESLI NA DRODZE JEST COS DO BICIA KONTYNUUJ RUCH
                            {
                                conti=true;
                                return true;
                            }
                        }

                    }
                    helpX++;
                    helpY--;
                }

                helpX=x;
                helpX_2=helpX;
                helpY=y;
                helpY_2=helpY;
                while(helpX>0 && helpY>0) //BICIE LEWO DOL
                {
                    if(moveCheckComp(x,y,helpX,helpY,aktualny))  //SPRAWDZAM CZY RUCH WGL MOZLIWY
                    {
                        helpX_2=helpX;
                        helpY_2=helpY;

                        while(helpX_2!=x && helpY_2!=y)            //COFAM SIE I JESLI NA WCZESNIEJSZYCH POLACH BYLBY PUSTE POLA TO FALSE BICIE NIE BEDZIE KONTUNUOWANE
                        {
                            k=0;
                            while(board[k++].colour!='o')                        //SZUKAM W TABLICY DANEGO POLA I SPRAWDZAM CO W NIM JEST
                            {
                                if(board[k].x==helpX_2 && board[k].y==helpY_2)
                                {
                                    if(board[k].colour=='c' || board[k].colour=='q' || board[k].colour=='b' || board[k].colour=='u' )
                                    {
                                        l4++;
                                        break;
                                    }
                                }

                            }
                            helpX_2++;
                            helpY_2++;
                            if(l4>0)               // JESLI NA DRODZE JEST COS DO BICIA KONTYNUUJ RUCH
                            {
                                conti=true;
                                return true;
                            }
                        }

                    }
                    helpX--;
                    helpY--;
                }

                if(l1==0 && l2==0 && l3==0 && l4==0)
                    return false;
            }

        }
        else
        {
            return false;
        }
    }
    return false;
}


bool game::win()
{
    int k=0;
    int amountBlack=0, amountWhite=0;
    while(board[k++].colour!='o')
    {
        if(board[k].colour=='c'|| board[k].colour=='q')
            amountBlack++;
        if(board[k].colour=='b'|| board[k].colour=='u')
            amountWhite++;
    }

    if(amountBlack==0 && amountWhite>0)
    {
        cout<<"WYGRYWA GRACZ ZIELONY"<<endl;
        return true;
    }
    else if(amountWhite==0 && amountBlack>0)
    {
        cout<<"WYGRYWA GRACZ CZERWONY"<<endl;
        return true;
    }

    return false;
}

/* DZIALAAAA
void game::show() // NAJPIERW LITERKA POTEM LICZBA
{
    int y,y2;
    warc x,x2;
    toArray();
    string aktualny=czarny;
    while(!win())
    {

        toArray();

        makeListChoice(aktualny);
        cout<<"Ruch gracza "<<aktualny<<endl
            <<"Wybierz pionek (litera liczba np.f 5):"<<endl;

        do
        {
            cin>>x;
            cin>>y;

        }
        while(!choiceCheck(x,y,aktualny));

        do
        {
            fight=false;
            cout<<"Ruch pionka: "<<x<<" "<<y<<endl<<endl;
            cout<<"Gdzie chcesz się ruszyć(litera liczba np.f 5)?"<<endl;
            do
            {
                cin>>x2;
                cin>>y2;
            }
            while(!moveCheck(x,y,x2,y2,aktualny));
            move(x,y,x2,y2,aktualny);
            dame(aktualny);
            conti=false;
            x=x2;
            y=y2;
            toArray();
        }
        while(continueMove(x2,y2,aktualny));


        if(aktualny==czarny)
            aktualny=bialy;
        else
            aktualny=czarny;

    }
} */

void game::show() // NAJPIERW LITERKA POTEM LICZBA
{
    int y,y2;
    warc x,x2;
    toArray();
    string aktualny=czarny;
    while(!win())
    {

        toArray();

        makeListChoice(aktualny);
        cout<<"Ruch gracza "<<aktualny<<endl
            <<"Wybierz pionek (litera liczba np.f 5):"<<endl;

        do
        {
            cin>>x;
            cin>>y;

        }
        while(!checkI(x,y,aktualny));

        do
        {
            fight=false;
            cout<<"Ruch pionka: "<<x<<" "<<y<<endl<<endl;
            cout<<"Gdzie chcesz się ruszyć(litera liczba np.f 5)?"<<endl;
            do
            {
                cin>>x2;
                cin>>y2;
            }
            while(!checkII(x,y,x2,y2,aktualny));
            moveCheck(x,y,x2,y2,aktualny);
            move(x,y,x2,y2,aktualny);
            dame(aktualny);
            conti=false;
            x=x2;
            y=y2;
            toArray();
        }
        while(continueMove(x2,y2,aktualny));


        if(aktualny==czarny)
            aktualny=bialy;
        else
            aktualny=czarny;

    }
}

void game::test()
{
    int k=0;
    while(board[k++].colour!='o')
    {
        if(board[k].x==c && board[k].y==1)
        {
            board[k].colour='d';

            break;
        }
    }
    k=0;
    while(board[k++].colour!='o')
    {
        if(board[k].x==b && board[k].y==4)
        {
            board[k].colour='d';

            break;
        }
    }
    k=0;
    while(board[k++].colour!='o')
    {
        if(board[k].x==d && board[k].y==4)
        {
            board[k].colour='c';

            break;
        }
    }
    k=0;
    while(board[k++].colour!='o')
    {
        if(board[k].x==c && board[k].y==5)
        {
            board[k].colour='b';

            break;
        }
    }
    k=0;
    while(board[k++].colour!='o')
    {
        if(board[k].x==e && board[k].y==3)
        {
            board[k].colour='d';

            break;
        }
    }
    k=0;
    while(board[k++].colour!='o')
    {
        if(board[k].x==c && board[k].y==5)
        {
            board[k].colour='b';

            break;
        }
    }
}


/* FUNKCJA BEZ WYBIJANIA ALERTOW NA KONSOLE */
bool game::moveCheckComp(int x,int y,int x2,int y2,string aktualny)
{
    bool murder=false;
    bool dama=false;
    int temp;

    int k=0; // SPRAWDZA CZY POLE PUSTE
    while(board[k++].colour!='o')
    {
        if(board[k].x==x2 && board[k].y==y2)
        {
            if(board[k].colour!='d')
            {
                return false;
            }
            else if(board[k].x==0 && board[k].x==9)
            {
                return false;
            }
        }
    }


    int d=0;
    while(board[d++].colour!='o')  // SPRAWDZA CZY PIONEK JEST DAMA
    {
        if(board[d].x==x && board[d].y==y)
        {
            if(board[d].colour=='q' || board[d].colour=='u')
            {
                dama=true;
            }
        }
    }


    if( (abs(y2-y) > 2 || abs(x2-x) > 2) && dama==false ) // ZALOZENIA DLA PIONKOW
    {
        return false;
    }

    if(x2<1 || x2>8 || y2>8 || y2<1) // BLOKADA RUCHU POZA POLE
        return false;

    if( (abs(y2-y)==1 || y2==y) && dama==false)   // RUCH O JEDEN y2==y wpuszczam ale potem to wylapuje
    {
        if(aktualny==czarny && ((abs(x2-x)!=1) || (y2!=y+1)  ))
        {
            return false;
        }
        if(aktualny==bialy && ((abs(x2-x)!=1) || (y2!=y-1)  ))
        {
            return false;
        }
        if(conti)  // JESLI JESTEM W STANIE BICIA TO RUCH PO BICIU NIE MOZE BYC O JEDEN
        {

            if((x2-x)<2)
                return false;
        }
    }



    if( abs(y2-y)==2 && dama==false )  //RUCH O DWA CZYLI SPRAWDZAMY BICIE PIONKOW
    {
        /*SZUKAM POLA POMIEDZY */
        k=0;
        while(board[k++].colour!='o') //
        {
            if(aktualny==czarny && x2>x)  // RUCH CZARNEGO SPRAWDZAMY CO JEST NA JEGO DRODZE
            {
                if(board[k].x==x2-1 && board[k].y==y2-1 )
                {

                    if(board[k].colour=='b' || board[k].colour=='u')
                    {
                        murder=true;
                        break;
                    }
                    else if(board[k].colour=='d' || board[k].colour=='c'|| board[k].colour=='q' ) // PRZEZ TAKIE PIONKI NIE SKACZEMY
                    {
                        return false;

                    }

                }
            }
            else if(aktualny==czarny && x2<x) // W LEWO CZARNY
            {
                if(board[k].x==x2+1 && board[k].y==y2-1 )
                {
                    if(board[k].colour=='b' || board[k].colour=='u')
                    {
                        murder=true;
                        break;
                    }
                    else if(board[k].colour=='d'|| board[k].colour=='c' || board[k].colour=='q')
                    {

                        return false;
                    }
                }
            }


            if(aktualny==bialy && x2>x)  // RUCH BIALEGO SPRAWDZAMY CO JEST NA JEGO DRODZE
            {
                if(board[k].x==x2-1 && board[k].y==y2+1 )
                {
                    if(board[k].colour=='c' || board[k].colour=='q') // TU NASTEPUJE BICIE
                    {
                        murder=true;
                        break;
                    }
                    else if(board[k].colour=='d' || board[k].colour=='b' || board[k].colour=='u')
                    {
                        return false;
                    }
                }
            }
            else if(aktualny==bialy && x2<x )
            {
                if(board[k].x==x2+1 && board[k].y==y2+1 )
                {
                    if(board[k].colour=='c' || board[k].colour=='q') // TU NASTEPUJE BICIE
                    {
                        murder=true;
                        break;
                    }
                    else if(board[k].colour=='d' || board[k].colour=='b' || board[k].colour=='u')
                    {

                        return false;
                    }
                }
            }
        }


        if(aktualny==czarny && ((abs(x2-x)!=2) || (y2!=y+2)) )
        {

            return false;
        }
        if(aktualny==bialy && ((abs(x2-x)!=2) || (y2!=y-2)) )
        {

            return false;
        }


    } /* KONIEC SPRAWDZANIA RUCHU O DWA */

    /* DAMA */
    if(dama)
    {
        if( abs(x2-x)!=abs(y2-y) )
        {

            return false;
        }


        /* BICIE DAMKI */
        int n=0;
        int l=0;
        k=0;

        while(board[k++].colour!='o')                                      /* WSZYSTKIE STROY CZARNY I BIALY */
        {
            if(aktualny==czarny) // DROGA CZARNEGO
            {
                if(board[k].x==x2 && board[k].y==y2) //SPRAWDZANIE DROGI DO CELU
                {

                    while(x2!=x && y2!=y)
                    {

                        while(board[n++].colour!='o')
                        {
                            if(board[n].x==x2 && board[n].y==y2 && (board[n].colour=='c' || board[n].colour=='q') )
                            {

                                return false;
                            }
                            else if(board[n].x==x2 && board[n].y==y2 && (board[n].colour=='b' || board[n].colour=='u'))
                            {
                                temp=n;
                                l++;
                                if(l>1)
                                {

                                    return false;
                                }
                            }

                        }


                        if(x2>x && y2>y) // PRAWA GORA
                        {
                            --x2;
                            --y2;
                        }
                        else if(x2<x && y2>y) //LEWA GORA
                        {
                            ++x2;
                            --y2;
                        }
                        else if(x2>x && y2<y) //PRAWA DOL
                        {
                            --x2;
                            ++y2;
                        }
                        else if(x2<x && y2<y) //LEWA DOL
                        {
                            ++x2;
                            ++y2;
                        }
                        n=0;
                    }
                    if(l==1)
                        murder=true;
                    break;
                }
            }



            if(aktualny==bialy) // DROGA BIALEGO
            {
                if(board[k].x==x2 && board[k].y==y2) //SPRAWDZANIE DROGI DO CELU
                {

                    while(x2!=x && y2!=y)
                    {

                        while(board[n++].colour!='o')
                        {
                            if(board[n].x==x2 && board[n].y==y2 && (board[n].colour=='b' || board[n].colour=='u') )
                            {

                                return false;
                            }
                            else if(board[n].x==x2 && board[n].y==y2 && (board[n].colour=='c' || board[n].colour=='q'))
                            {
                                temp=n;
                                l++;
                                if(l>1)
                                {

                                    return false;
                                }
                            }

                        }


                        if(x2>x && y2>y) // PRAWA GORA
                        {
                            --x2;
                            --y2;
                        }
                        else if(x2<x && y2>y) //LEWA GORA
                        {
                            ++x2;
                            --y2;
                        }
                        else if(x2>x && y2<y) //PRAWA DOL
                        {
                            --x2;
                            ++y2;
                        }
                        else if(x2<x && y2<y) //LEWA DOL
                        {
                            ++x2;
                            ++y2;
                        }
                        n=0;
                    }
                    if(l==1)
                        murder=true;
                    break;
                }
            }

            if(conti) // W PRZYPADKU BICIA NASTEPNY RUCH O ILE ISTNIEJE MUSI BIC POMOC DLA FUNKCJI CONTINUE
            {
                if(board[k].x==x2 && board[k].y==y2) //SPRAWDZANIE DROGI DO CELU
                {

                    while(x2!=x && y2!=y)
                    {

                        while(board[n++].colour!='o')
                        {
                            if(board[n].x==x2 && board[n].y==y2 && (board[n].colour=='b' || board[n].colour=='u' || (board[n].colour!='c' || board[n].colour=='q')))
                            {
                                temp=n;
                                l++;
                            }

                        }


                        if(x2>x && y2>y) // PRAWA GORA
                        {
                            --x2;
                            --y2;
                        }
                        else if(x2<x && y2>y) //LEWA GORA
                        {
                            ++x2;
                            --y2;
                        }
                        else if(x2>x && y2<y) //PRAWA DOL
                        {
                            --x2;
                            ++y2;
                        }
                        else if(x2<x && y2<y) //LEWA DOL
                        {
                            ++x2;
                            ++y2;
                        }
                        n=0;
                    }
                    if( l!=1 )
                    {
                        return false;
                    }
                    break;
                }
            }

        }
    }

    return true;
}


bool game::choiceCheckComp(int x,int y,string aktualny)
{

    int k=0;
    while(board[k++].colour!='o')
    {
        if(board[k].x==x && board[k].y==y)
        {
            if(board[k].colour=='d')
            {
                return false;
            }
            else if(board[k].colour=='c' && aktualny==bialy)
            {
                return false;
            }
            else if(board[k].colour=='b' && aktualny==czarny)
            {
                return false;
            }
            else if(board[k].colour=='q' && aktualny==bialy)
            {
                return false;
            }
            else if(board[k].colour=='u' && aktualny==czarny)
            {
                return false;
            }
            else if(board[k].x==0 || board[k].x==9)
            {
                return false;
            }
            else if(board[k].colour=='p' )
            {
                return false;
            }
            else
                return true; //Wybrano pionek poprawnie
        }

    }
    return true;
}

/*
void game::show() // DO TESTOW Z PRZYCISKIEM NA ZMIANE GRACZA
{
    int y,y2,test=1;
    warc x,x2;
    toArray();
    string aktualny=czarny;
    while(test)
    {
        do
        {
            toArray();
            makeListChoice(aktualny);
            cout<<"Ruch gracza "<<aktualny<<endl
                <<"Wybierz pionek (litera liczba np.f 5):"<<endl;

            do
            {
                cin>>x;
                if(x==s)
                    break;
                cin>>y;

            }
            while(!choiceCheck(x,y,aktualny));


            cout<<"Wybrany pionek to: "<<x<<" "<<y<<endl<<endl;
            cout<<"Gdzie chcesz się ruszyć(litera liczba np.f 5)?"<<endl;
            if(x!=s)
                do
                {
                    cin>>x2;
                    cin>>y2;
                }
                while(!moveCheck(x,y,x2,y2,aktualny));
            if(x!=s)
                move(x,y,x2,y2,aktualny);


        }
        while(x!=s);
        if(aktualny==czarny)
            aktualny=bialy;
        else
            aktualny=czarny;

    }
}*/
