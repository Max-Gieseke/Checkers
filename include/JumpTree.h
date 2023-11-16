//
// Created by maxgi on 12/21/2022.
//

#ifndef MOVETREE_H
#define MOVETREE_H
#include "Move.h"
#include <memory>
#include "JumpNode.h"

class JumpTree {
private:
     std::shared_ptr<JumpNode> root;
public:
    JumpTree();
    JumpTree(small, CheckerBoard);
    std::vector<Move> jumpMoves();
    std::shared_ptr<JumpNode> getRoot();
    static std::vector<Move> getJumps(small, const CheckerBoard&);
    static std::vector<std::pair<small, small>> singleJump(small, const CheckerBoard&);
    static std::vector<Move> possibleMoves(const CheckerBoard&);
    /**
     * Gets most jumps from a list of moves
     * @return the number of jumps a list of moves has
     */
    static small maxJumps(std::vector<Move>);
    void clearTree();


};


#endif //MOVETREE_H
