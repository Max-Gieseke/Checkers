//
// Created by maxgi on 12/21/2022.
//

#ifndef MOVETREE_H
#define MOVETREE_H
#include "Move.h"
#include <memory>
#include "CheckerBoard.h"
#include "JumpNode.h"

class JumpTree {
private:
     std::shared_ptr<JumpNode> root;
public:
    JumpTree();
    JumpTree(small, CheckerBoard);
    std::vector<Move> jumpMoves();
    std::shared_ptr<JumpNode> getRoot();
    void clearTree();


};


#endif //MOVETREE_H
