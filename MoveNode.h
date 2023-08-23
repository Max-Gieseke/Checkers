//
// Created by maxgi on 8/23/2023.
//

#ifndef CHECKERS_MOVENODE_H
#define CHECKERS_MOVENODE_H
#include "Board.h"


class MoveNode {
private:
    Board curBoard;
    int depthSearched;
    double score;
    vector<MoveNode*> next;
    Move bestMove;
    MoveNode* parent;
    friend class MoveTree;
public:
    MoveNode();
    MoveNode(Board);
    MoveNode(Board, int, double, MoveNode*);
    double exploreMoves(int);

    void addChild(MoveNode*);
    Move getBestMove();
    Board getBoard();
    int getDepth();
};


#endif //CHECKERS_MOVENODE_H
