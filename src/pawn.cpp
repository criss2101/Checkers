#include "pawn.h"
using namespace std;

pawn::pawn(int _x,int _y,char _colour){
x=_x;
y=_y;
colour=_colour;
}

pawn::pawn(){
x=-1;
y=-1;
colour='d';
}

void pawn::dead(){
colour='d';
}

