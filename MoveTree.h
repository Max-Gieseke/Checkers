//
// Created by maxgi on 12/21/2022.
//

#ifndef MOVETREE_H
#define MOVETREE_H
#include <vector>
#include "Move.h"
#include <iostream>

using namespace std;
class MoveTree {
    using small = unsigned char;
private:
     small square;
     small depth;
     small jumped;
     vector<MoveTree*> next;
     MoveTree* parent;
     small board[32];
public:
    MoveTree();
    MoveTree(small, small*);
    MoveTree(small, small, MoveTree*, small*);
    MoveTree(small, small, small, MoveTree*, small*);
    small getSquare();
    small getDepth();
    small* getBoard();
    void addChild(MoveTree*);
    vector<MoveTree*> getNext();
    MoveTree* getParent();
    small maxDepth();
    void getRemainingSequence(vector<small>&);
    void maxSequences(small, vector<vector<small>>&);
    static vector<Move> jumpMoves(MoveTree);
    small getJumped(small, small);
//    vector<MoveTree>* getSquare(small, small);
//    void addSquare(small, small);
    friend ostream &operator<<(ostream &out, MoveTree m);


};


#endif //MOVETREE_H
