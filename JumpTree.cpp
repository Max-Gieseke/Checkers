//
// Created by maxgi on 12/21/2022.
//

#include "JumpTree.h"
using small = unsigned char;

JumpTree::JumpTree() {
    square = 64;
    depth = 0;
    next = std::vector<JumpTree*>();
    parent = nullptr;
}
JumpTree::JumpTree(small square, small* board) {
    this->square = square;
    depth = 0;
    jumped = 64;
    next = std::vector<JumpTree*>();
    parent = nullptr;
    copy(board, board+32, this->board);
}

JumpTree::JumpTree(small square, small depth, JumpTree* p, small* board) {
    this->square = square;
    this->depth = depth;
    parent = p;
    next = std::vector<JumpTree*>();
    std::copy(board, board+32, this->board);
}

JumpTree::JumpTree(small square, small depth, small jumped, JumpTree* p, small* board) {
    this->square = square;
    this->depth = depth;
    this->jumped = jumped;
    parent = p;
    next = std::vector<JumpTree*>();
    copy(board, board+32, this->board);
}

JumpTree::small JumpTree::getSquare() {
    return square;
}

JumpTree::small JumpTree::getDepth() {
    return depth;
}

std::vector<JumpTree*> JumpTree::getNext() {
    return next;
}

JumpTree* JumpTree::getParent() {
    return parent;
}

void JumpTree::addChild(JumpTree* child) {
    this->next.push_back(child);
}

small JumpTree::maxDepth() {
    if(this->next.empty()){
        return depth;
    }
    small max = 0;
    for(JumpTree* n : next){
        if(n->maxDepth() > max){
            max = n->maxDepth();
        }
    }
    return max;
}

void JumpTree::getRemainingSequence(std::vector<small>& holder){
    if(depth == 0){
        holder.push_back(square);
    }
    else{
        holder.push_back(jumped);
        this->parent->getRemainingSequence(holder);
    }
}

void JumpTree::maxSequences(small depth, std::vector<std::vector<small>>& holder) {
    if(this->depth == depth){
        holder.push_back(std::vector<small>());
        holder.back().push_back(this->square);
        getRemainingSequence(holder.back());
    }
    else{
        for(JumpTree* node : this->next){
            node->maxSequences(depth, holder);
        }
    }

}



std::vector<Move> JumpTree::jumpMoves(JumpTree head) {
    small longest = head.maxDepth();
    if(longest == 0){
        return std::vector<Move>();
    }
    std::vector<std::vector<small>> invertedJumps;
    head.maxSequences(longest, invertedJumps);
    vector<Move> holder;
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

small *JumpTree::getBoard() {
    return this->board;
}

std::ostream &operator<<(std::ostream &out, JumpTree m) {
    out << "Current: " << (int)m.square << " Captured " << (int)m.jumped << std::endl;
    if(m.parent == nullptr){
        out << "Parent Square " << "none\n";
    }
    else{
        out << "Parent Square " << (int) m.parent->square << std::endl;

    }
    return out;
}



