#ifndef TREE_H
#define TREE_H
#include "node.h"
#include "game.h"
#include <vector>
#include "move.h"
class tree
{
    public:
        move ruch;
        tree();
        move createTree(int,int,game&gra,string);
        void comp();
        void calculate(node *p) ;
};

#endif // TREE_H
