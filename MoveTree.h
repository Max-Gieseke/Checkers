//
// Created by maxgi on 8/22/2023.
//
#include "Board.h"
#include "ZobristHash.h"
#include "TranspositionTable.h"
#include "MoveNode.h"
#include "Move.h"
#include <vector>
#ifndef CHECKERS_MOVETREE_H
#define CHECKERS_MOVETREE_H


class MoveTree {
private:
    MoveNode root;
    TranspositionTable exploredMoves;

public:
    MoveTree();
    MoveTree(Board);
    MoveNode getRoot();
    MoveTree(Board, int, double, MoveNode*);
    double exploreTree(int);
    double exploreMoves(int, MoveNode*);
    double explore(int, MoveNode*);
    void addElem(MoveNode*);
};



#endif //CHECKERS_MOVETREE_H
