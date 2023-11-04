//
// Created by maxgi on 8/23/2023.
//

#include "MoveNode.h"

MoveNode::MoveNode() {
    this->curBoard = CheckerBoard();
    this->depthSearched = 0;
    this->score = 0;
    this->parent = nullptr;
    this->next = std::vector<std::shared_ptr<MoveNode>>();
}

MoveNode::MoveNode(const CheckerBoard& b, int depthSearched, double score, std::shared_ptr<MoveNode> p, const Move& last) {
    this->curBoard = b;
    this->depthSearched = depthSearched;
    this->score = score;
    this->parent = p;
    this->lastMove = last;
    this->next = std::vector<std::shared_ptr<MoveNode>>();
}

MoveNode::MoveNode(const CheckerBoard& top) {
    this->curBoard = top;
    this->depthSearched = 0;
    this->parent = std::make_shared<MoveNode>();;
    this->next = std::vector<std::shared_ptr<MoveNode>>();
}

//MoveNode::~MoveNode() {
//    for(std::shared_ptr<MoveNode> node : this->next){
//        node->~MoveNode();
//    }
//}


void MoveNode::addChild(std::shared_ptr<MoveNode> child) {
    this->next.push_back(child);
}

Move MoveNode::getBestMove() {
    return bestMove;
}

Move MoveNode::getLastMove(){
    return lastMove;
}

CheckerBoard MoveNode::getBoard() {
    return curBoard;
}

int MoveNode::getDepth() const {
    return this->depthSearched;
}



MoveNode &MoveNode::operator=(const MoveNode& other) {
    if(this != &other){
        this->depthSearched = other.depthSearched;
        this->score = other.score;
        this->curBoard = other.curBoard;
        this->next = other.next;
        this->bestMove = other.bestMove;
        this->lastMove = other.lastMove;
        this->parent = other.parent;
    }
    return *this;
}

double MoveNode::getScore() const {
    return score;
}

std::vector<std::shared_ptr<MoveNode>> MoveNode::getNext() {
    return next;
}

