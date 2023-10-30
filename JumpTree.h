//
// Created by maxgi on 12/21/2022.
//

#ifndef MOVETREE_H
#define MOVETREE_H
#include "Move.h"

class JumpTree {
    using small = unsigned char;
private:
     small square;
     small depth;
     small jumped;
     std::vector<JumpTree*> next;
     JumpTree* parent;
     small board[32];
public:
    JumpTree();
    JumpTree(small, small*);
    JumpTree(small, small, JumpTree*, small*);
    JumpTree(small, small, small, JumpTree*, small*);
    small getSquare();
    small getDepth();
    small* getBoard();
    void addChild(JumpTree*);
    std::vector<JumpTree*> getNext();
    JumpTree* getParent();
    small maxDepth();
    void getRemainingSequence(std::vector<small>&);
    void maxSequences(small, std::vector<std::vector<small>>&);
    static vector<Move> jumpMoves(JumpTree);
    small getJumped(small, small);
//    vector<JumpTree>* getSquare(small, small);
//    void addSquare(small, small);
    friend std::ostream &operator<<(std::ostream &out, JumpTree m);


};


#endif //MOVETREE_H
