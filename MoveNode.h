//
// Created by maxgi on 8/23/2023.
//

#ifndef CHECKERS_MOVENODE_H
#define CHECKERS_MOVENODE_H
#include "CheckerLogic.h"


class MoveNode {
private:
    CheckerBoard curBoard;
    int depthSearched;
    double score;
    std::vector<std::shared_ptr<MoveNode>> next;
    Move bestMove;
    Move lastMove;
    std::shared_ptr<MoveNode> parent;
    friend class MoveTree;
public:
    MoveNode();
    MoveNode(const CheckerBoard&);
    MoveNode(const CheckerBoard&, int, double, std::shared_ptr<MoveNode>, const Move&);
    //~MoveNode();
    double exploreMoves(int);
    double getScore() const;
    void addChild(std::shared_ptr<MoveNode>);
    Move getBestMove();
    Move getLastMove();
    CheckerBoard getBoard();
    std::vector<std::shared_ptr<MoveNode>> getNext();
    int getDepth() const;
    MoveNode& operator=(const MoveNode&);
};


#endif //CHECKERS_MOVENODE_H
