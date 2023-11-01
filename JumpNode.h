//
// Created by maxgi on 10/31/2023.
//

#ifndef CHECKERS_JUMPNODE_H
#define CHECKERS_JUMPNODE_H
#include <vector>
#include <memory>
#include "CheckerBoard.h"

class JumpNode {
private:

    small square;
    small depth;
    small jumped;
    std::vector<std::shared_ptr<JumpNode>> next;
    std::shared_ptr<JumpNode> parent;
    CheckerBoard board;
public:
    JumpNode();
    JumpNode(small, CheckerBoard);
    JumpNode(small, small, std::shared_ptr<JumpNode>, CheckerBoard);
    JumpNode(small, small, small, std::shared_ptr<JumpNode>, CheckerBoard);

    small getDepth() const;
    small getSquare() const;
    std::vector<std::shared_ptr<JumpNode>> getNext();

    void addChild(std::shared_ptr<JumpNode> child);

    std::shared_ptr<JumpNode> getParent();

    void maxSequences(small curDepth, std::vector<std::vector<small>> &holder);

    void getRemainingSequence(std::vector<small> &holder);

    small maxDepth();

    CheckerBoard getBoard();

    friend std::ostream &operator<<(std::ostream&, const JumpNode&);
};


#endif //CHECKERS_JUMPNODE_H
