//
// Created by maxgi on 10/31/2023.
//

#include "JumpNode.h"


JumpNode::JumpNode() {
    square = 64;
    depth = 0;
    next = std::vector<std::shared_ptr<JumpNode>>();
    parent = nullptr;
}
JumpNode::JumpNode(small square, CheckerBoard board) {
    this->square = square;
    depth = 0;
    jumped = 64;
    next = std::vector<std::shared_ptr<JumpNode>>();
    parent = nullptr;
    this->board = board;
}

JumpNode::JumpNode(small square, small depth, std::shared_ptr<JumpNode> p, CheckerBoard board) {
    this->square = square;
    this->depth = depth;
    parent = p;
    next = std::vector<std::shared_ptr<JumpNode>>();
    this->board = board;
}

JumpNode::JumpNode(small square, small depth, small jumped, std::shared_ptr<JumpNode> p, CheckerBoard board) {
    this->square = square;
    this->depth = depth;
    this->jumped = jumped;
    parent = p;
    next = std::vector<std::shared_ptr<JumpNode>>();
    this->board = board;
}

small JumpNode::getSquare() const {
    return square;
}

small JumpNode::getDepth() const {
    return depth;
}

CheckerBoard JumpNode::getBoard() {
    return this->board;
}

std::vector<std::shared_ptr<JumpNode>> JumpNode::getNext() {
    return next;
}

std::shared_ptr<JumpNode> JumpNode::getParent() {
    return parent;
}

void JumpNode::addChild(std::shared_ptr<JumpNode> child) {
    this->next.push_back(child);
}

small JumpNode::maxDepth() {
    if(this->next.empty()){
        return depth;
    }
    small max = 0;
    for(std::shared_ptr<JumpNode> n : next){
        if(n->maxDepth() > max){
            max = n->maxDepth();
        }
    }
    return max;
}

void JumpNode::getRemainingSequence(std::vector<small>& holder){
    if(depth == 0){
        holder.push_back(square);
    }
    else{
        holder.push_back(jumped);
        this->parent->getRemainingSequence(holder);
    }
}

void JumpNode::maxSequences(small curDepth, std::vector<std::vector<small>>& holder) {
    if(this->depth == curDepth){
        holder.emplace_back();
        holder.back().push_back(this->square);
        getRemainingSequence(holder.back());
    }
    else{
        for(std::shared_ptr<JumpNode> node : this->next){
            node->maxSequences(curDepth, holder);
        }
    }

}

std::ostream &operator<<(std::ostream &out, const JumpNode& m) {
    out << "Current: " << (int)m.square << " Captured " << (int)m.jumped << std::endl;
    if(m.parent == nullptr){
        out << "Parent Square " << "none\n";
    }
    else{
        out << "Parent Square " << (int) m.parent->square << std::endl;

    }
    return out;
}

