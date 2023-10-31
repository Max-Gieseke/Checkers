//
// Created by maxgi on 12/21/2022.
//

#ifndef MOVETREE_H
#define MOVETREE_H
#include "Move.h"
#include <memory>

class JumpTree {
    using small = unsigned char;
private:
     small square;
     small depth;
     small jumped;
     std::vector<std::shared_ptr<JumpTree>> next;
     std::shared_ptr<JumpTree> parent;
     small board[32];
public:
    JumpTree();
    JumpTree(small, std::unique_ptr<small[]>);
    JumpTree(small, small, std::shared_ptr<JumpTree>, std::unique_ptr<small[]>);
    JumpTree(small, small, small, std::shared_ptr<JumpTree>, std::unique_ptr<small[]>);
    small getSquare() const;
    small getDepth() const;
    small* getBoard();
    void addChild(std::shared_ptr<JumpTree>);
    std::vector<std::shared_ptr<JumpTree>> getNext();
    std::shared_ptr<JumpTree> getParent();
    small maxDepth();
    void getRemainingSequence(std::vector<small>&);
    void maxSequences(small, std::vector<std::vector<small>>&);
    static std::vector<Move> jumpMoves(JumpTree);
    small getJumped(small, small);
//    vector<JumpTree>* getSquare(small, small);
//    void addSquare(small, small);
    friend std::ostream &operator<<(std::ostream &out, const JumpTree& m);


};


#endif //MOVETREE_H
