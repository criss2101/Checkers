#include <iostream>
#include "pawn.h"
#include "game.h"
#include "tree.h"
using namespace std;
ostream& operator <<(ostream& wyj,warc Arg);

istream& operator >>(istream& wej,warc& Arg);

int main()
{ int wybor;


cout<<"Witaj w grze warcaby !!"<<endl
    <<"1.Gra z komputerem"<<endl
    <<"2.Gra na dwoch graczy"<<endl;
    cin>>wybor;
    if(wybor==1){
    tree drzewo;
drzewo.comp();
}
    else if(wybor==2){
    game gra;
    gra.show();
    }
    else
    cout<<"Nie ma innych trybow gry ;/"<<endl;

return 0;
}
