//
// Created by maxgi on 8/22/2023.
//
#include "ZobristHash.h"
#include "TranspositionTable.h"
#include "MoveNode.h"
#ifndef CHECKERS_MOVETREE_H
#define CHECKERS_MOVETREE_H


class MoveTree {
private:
    std::shared_ptr<MoveNode> root;
    int getNodeSize(std::shared_ptr<MoveNode>);

public:
    MoveTree();
    MoveTree(CheckerBoard);
    std::shared_ptr<MoveNode> getRoot();
    MoveTree(CheckerBoard, int, double, std::shared_ptr<MoveNode>);
    // ~MoveTree();
    double exploreTree(int);
    double exploreMoves(int,std::shared_ptr<MoveNode>);
    double explore(int, std::shared_ptr<MoveNode>);
    void addElem(std::shared_ptr<MoveNode>);
    void updateRoot(const Move&);
    int getTreeSize();
};



#endif //CHECKERS_MOVETREE_H
