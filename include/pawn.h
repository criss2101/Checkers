#ifndef PAWN_HH
#define PAWN_HH
enum colour{black,white};
class pawn{
public:
int x,y;
char colour;
pawn();
pawn(int,int,char);


void dead();


};

#endif
