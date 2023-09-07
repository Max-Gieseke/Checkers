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
    Move lastMove;
    MoveNode* parent;
    friend class MoveTree;
public:
    MoveNode();
    MoveNode(Board);
    MoveNode(Board, int, double, MoveNode*, Move);
    double exploreMoves(int);
    double getScore();
    void addChild(MoveNode*);
    Move getBestMove();
    Move getLastMove();
    Board getBoard();
    vector<MoveNode*> getNext();
    int getDepth();
    MoveNode& operator=(const MoveNode&);
};


#endif //CHECKERS_MOVENODE_H
