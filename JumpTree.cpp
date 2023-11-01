//
// Created by maxgi on 12/21/2022.
//

#include "JumpTree.h"

JumpTree::JumpTree(small square, CheckerBoard board) {
    root = std::make_shared<JumpNode>(square, board);
}

std::shared_ptr<JumpNode> JumpTree::getRoot() {
    return root;
}



std::vector<Move> JumpTree::jumpMoves() {
    small longest = root->maxDepth();
    if(longest == 0){
        return std::vector<Move>();
    }
    std::vector<std::vector<small>> invertedJumps;
    root->maxSequences(longest, invertedJumps);
    std::vector<Move> holder;
    //seq[0] is last position, seq.back() is first square, all others are jumps
    for(std::vector<small> seq : invertedJumps){
        Move tmp = Move(seq.back(), seq.front());
        for(int i = 1; i < seq.size() - 1; i++){
            tmp.addJump(seq[i]);
        }
        holder.push_back(tmp);
    }

    return holder;
}



