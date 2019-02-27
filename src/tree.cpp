#include "tree.h"
#include "unistd.h"
ostream& operator <<(ostream& wyj,warc Arg);
istream& operator >>(istream& wej,warc& Arg);
tree::tree()
{

}

// NA CZTERY
move tree::createTree(int x,int y,game &gra,string aktualny){
vector<pawn> listChoiceB,listChoiceB2;
vector<pawn> listMoveB,listMoveB2;
vector<pawn> listChoiceC,listChoiceC2;
vector<pawn> listMoveC,listMoveC2;
int maxx=-10000;

if(!gra.conti){
listChoiceB=gra.makeListChoice(aktualny); //ROBIE LISTE RUCHOW DLA DANEJ GRY I AKTUALNEGO GRACZA
for(int i=0;i<listChoiceB.size();i++){
listMoveB=gra.makeListMove(listChoiceB[i],aktualny);
for(int j=0;j<listMoveB.size();j++){
node *nowy=new node(gra);
nowy->pawnn=listMoveB[j];
nowy->giera.moveCheck(listChoiceB[i].x,listChoiceB[i].y,listMoveB[j].x,listMoveB[j].y,aktualny);
nowy->giera.move(listChoiceB[i].x,listChoiceB[i].y,listMoveB[j].x,listMoveB[j].y,aktualny);
nowy->giera.dame(aktualny);


listChoiceC=nowy->giera.makeListChoice(gra.czarny);
for(int k=0;k<listChoiceC.size();k++){
listMoveC=nowy->giera.makeListMove(listChoiceC[k],gra.czarny);
for(int l=0;l<listMoveC.size();l++){
node *nowy2=new node(nowy->giera);
nowy2->giera.moveCheck(listChoiceC[k].x,listChoiceC[k].y,listMoveC[l].x,listMoveC[l].y,gra.czarny);
nowy2->giera.move(listChoiceC[k].x,listChoiceC[k].y,listMoveC[l].x,listMoveC[l].y,gra.czarny);
nowy2->giera.dame(gra.czarny);


listChoiceB2=nowy2->giera.makeListChoice(gra.bialy);
for(int w=0;w<listChoiceB2.size();w++){
listMoveB2=nowy2->giera.makeListMove(listChoiceB2[w],gra.bialy);
for(int v=0;v<listMoveB2.size();v++){
node *nowy3=new node(nowy2->giera);
nowy3->giera.moveCheck(listChoiceB2[w].x,listChoiceB2[w].y,listMoveB2[v].x,listMoveB2[v].y,gra.bialy);
nowy3->giera.move(listChoiceB2[w].x,listChoiceB2[w].y,listMoveB2[v].x,listMoveB2[v].y,gra.bialy);
nowy3->giera.dame(gra.bialy);

listChoiceC2=nowy3->giera.makeListChoice(gra.czarny);
for(int t=0;t<listChoiceC2.size();t++){
listMoveC2=nowy3->giera.makeListMove(listChoiceC2[t],gra.czarny);
for(int z=0;z<listMoveC2.size();z++){
node *nowy4=new node(nowy3->giera);
nowy4->giera.moveCheck(listChoiceC2[t].x,listChoiceC2[t].y,listMoveC2[z].x,listMoveC2[z].y,gra.czarny);
nowy4->giera.move(listChoiceC2[t].x,listChoiceC2[t].y,listMoveC2[z].x,listMoveC2[z].y,gra.czarny);
nowy4->giera.dame(gra.czarny);
calculate(nowy4);
if(nowy4->wynik>maxx){
ruch.x=listChoiceB[i].x;  ruch.y=listChoiceB[i].y; ruch.x2=nowy->pawnn.x; ruch.y2=nowy->pawnn.y;
maxx=nowy->wynik;
}

delete nowy4;
}
}
delete nowy3;
}
}
delete nowy2;
}
}
delete nowy;
}
}


return ruch;
}
else{
    int k=0;
    while(gra.board[k++].colour!='o')
    if(gra.board[k].x==x && gra.board[k].y==y){
    pawn test(x,y,'b');
    listChoiceB=gra.makeListMove(test,gra.bialy);
    ruch.x=x;
    ruch.y=y;
    ruch.x2=listChoiceB[0].x;
    ruch.y2=listChoiceB[0].y;
    gra.conti=false;
    return ruch;
    }
}
return ruch;
}

/* NA JEDEN
move tree::createTree(int x,int y,game &gra,string aktualny)
{
    vector<pawn> listChoiceB;
    vector<pawn> listMoveB;
    vector<pawn> listChoiceC;
    vector<pawn> listMoveC;
    int maxx=-5000;


    listChoiceB=gra.makeListChoice(aktualny); //ROBIE LISTE RUCHOW DLA DANEJ GRY I AKTUALNEGO GRACZA
    for(int i=0; i<listChoiceB.size(); i++)
    {
        listMoveB=gra.makeListMove(listChoiceB[i],aktualny);
        for(int j=0; j<listMoveB.size(); j++)
        {
            node *nowy=new node(gra);
            nowy->pawnn=listMoveB[j];
            nowy->giera.moveCheck(listChoiceB[i].x,listChoiceB[i].y,listMoveB[j].x,listMoveB[j].y,aktualny);
            nowy->giera.move(listChoiceB[i].x,listChoiceB[i].y,listMoveB[j].x,listMoveB[j].y,aktualny);
            nowy->giera.dame(aktualny);


                    calculate(nowy);
                    if(nowy->wynik>maxx)
                    {
                        ruch.x=listChoiceB[i].x;
                        ruch.y=listChoiceB[i].y;
                        ruch.x2=nowy->pawnn.x;
                        ruch.y2=nowy->pawnn.y;
                        maxx=nowy->wynik;
                    }
delete nowy;
                }



        }



    cout<<"MAX WYNIK TO:"<<maxx<<endl;
    return ruch;

}*/
/*
//NA DWA
move tree::createTree(int x,int y,game &gra,string aktualny)
{
    vector<pawn> listChoiceB;
    vector<pawn> listMoveB;
    vector<pawn> listChoiceC;
    vector<pawn> listMoveC;
    int maxx=-5000;


    if(!gra.conti)
    {
    listChoiceB=gra.makeListChoice(aktualny); //ROBIE LISTE RUCHOW DLA DANEJ GRY I AKTUALNEGO GRACZA
    for(int i=0; i<listChoiceB.size(); i++)
    {
        listMoveB=gra.makeListMove(listChoiceB[i],aktualny);
        for(int j=0; j<listMoveB.size(); j++)
        {
            node *nowy=new node(gra);
            nowy->pawnn=listMoveB[j];
            nowy->giera.moveCheck(listChoiceB[i].x,listChoiceB[i].y,listMoveB[j].x,listMoveB[j].y,aktualny);
            nowy->giera.move(listChoiceB[i].x,listChoiceB[i].y,listMoveB[j].x,listMoveB[j].y,aktualny);
            nowy->giera.dame(aktualny);

            listChoiceC=nowy->giera.makeListChoice(gra.czarny);
            for(int k=0; k<listChoiceC.size(); k++)
            {
                listMoveC=nowy->giera.makeListMove(listChoiceC[k],gra.czarny);
                for(int l=0; l<listMoveC.size(); l++)
                {
                    nowy->giera.moveCheck(listChoiceC[k].x,listChoiceC[k].y,listMoveC[l].x,listMoveC[l].y,gra.czarny);
                    nowy->giera.move(listChoiceC[k].x,listChoiceC[k].y,listMoveC[l].x,listMoveC[l].y,gra.czarny);
                    nowy->giera.dame(gra.czarny);

                    calculate(nowy);
                    if(nowy->wynik>maxx)
                    {
                        ruch.x=listChoiceB[i].x;
                        ruch.y=listChoiceB[i].y;
                        ruch.x2=nowy->pawnn.x;
                        ruch.y2=nowy->pawnn.y;
                        maxx=nowy->wynik;
                    }

                }
            }

           delete nowy;
        }

    }

    cout<<"MAX WYNIK TO:"<<maxx<<endl;
    return ruch;}
    else{
    int k=0;
    while(gra.board[k++].colour!='o')
    if(gra.board[k].x==x && gra.board[k].y==y){
    pawn test(x,y,'b');
    listChoiceB=gra.makeListMove(test,gra.bialy);
    ruch.x=x;
    ruch.y=y;
    ruch.x2=listChoiceB[0].x;
    ruch.y2=listChoiceB[0].y;
    gra.conti=false;
    return ruch;
    }
}


}*/

void tree::calculate(node *p)
{
    int wynik=0;
    int k=0;
    while(p->giera.board[k++].colour!='o')
    {

        if(p->giera.board[k].colour=='u')
            wynik+=1000;
        else if(p->giera.board[k].colour=='c')
            wynik-=100;
        else if(p->giera.board[k].colour=='q')
            wynik-=500;
        else if(p->giera.board[k].colour=='b' && (p->giera.board[k].y==8 || p->giera.board[k].y==7))
            wynik+=15;
        else if(p->giera.board[k].colour=='b' && (p->giera.board[k].y==6 || p->giera.board[k].y==5))
            wynik+=10;
        else if(p->giera.board[k].colour=='b' && (p->giera.board[k].y==5 || p->giera.board[k].y==4))
            wynik+=5;
        else if(p->giera.board[k].colour=='b' && (p->giera.board[k].y==3 || p->giera.board[k].y==2 || p->giera.board[k].y==1))
            wynik+=2;
            else if(p->giera.conti)
            wynik-=50;
    }

    p->wynik=wynik;
//cout<<"Wynik dla ruchu:"<<p->pawnn.x<<p->pawnn.y<<" : "<<p->wynik<<endl;
}


void tree::comp()
{
    game gra;
    move ruch;
    ruch.x2=0;
    ruch.y2=0;
    int y,y2;
    warc x,x2;
    gra.toArray();
    string aktualny=gra.czarny;
    while(!gra.win())
    {

        cout<<"Ruch gracza "<<aktualny<<endl
            <<"Wybierz pionek (litera liczba np.f 5):"<<endl;

        do
        {
            cin>>x;
            cin>>y;

        }
        while(!gra.choiceCheck(x,y,aktualny));

        do
        {
            gra.fight=false;
            cout<<"Ruch pionka: "<<x<<" "<<y<<endl<<endl;
            cout<<"Gdzie chcesz się ruszyć(litera liczba np.f 5)?"<<endl;
            do
            {
                cin>>x2;
                cin>>y2;
            }
            while(!gra.moveCheck(x,y,x2,y2,aktualny));
            gra.move(x,y,x2,y2,aktualny);
            gra.dame(aktualny);
            gra.conti=false;
            x=x2;
            y=y2;
            gra.toArray();
        }
        while(gra.continueMove(x2,y2,aktualny));
        usleep(800000);
        if(!gra.win())
        {
            do
            {
                ruch=createTree(ruch.x2,ruch.y2,gra,gra.bialy);
                gra.moveCheck(ruch.x,ruch.y,ruch.x2,ruch.y2,gra.bialy);
                gra.move(ruch.x,ruch.y,ruch.x2,ruch.y2,gra.bialy);
                gra.dame(gra.bialy);
                gra.conti=false;
                gra.toArray();
            }
            while(gra.continueMove(ruch.x2,ruch.y2,gra.bialy));
        }

        /*if(aktualny==czarny)
            aktualny=bialy;
        else
            aktualny=czarny;*/

    }
}








