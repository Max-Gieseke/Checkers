//
// Created by maxgi on 8/23/2023.
//

#include "MoveNode.h"

MoveNode::MoveNode() {
    this->curBoard = Board();
    this->depthSearched = 0;
    this->score = 0;
    this->parent = nullptr;
    this->next = std::vector<MoveNode*>();
}

MoveNode::MoveNode(Board b, int depthSearched, double score, MoveNode* p, const Move& last) {
    this->curBoard = b;
    this->depthSearched = depthSearched;
    this->score = score;
    this->parent = p;
    this->lastMove = last;
    this->next = std::vector<MoveNode*>();
}

MoveNode::~MoveNode() {
    for(MoveNode* node : this->next){
        node->~MoveNode();
    }
}


void MoveNode::addChild(MoveNode * child) {
    this->next.push_back(child);
}

Move MoveNode::getBestMove() {
    return bestMove;
}

Move MoveNode::getLastMove(){
    return lastMove;
}

Board MoveNode::getBoard() {
    return curBoard;
}

int MoveNode::getDepth() const {
    return this->depthSearched;
}

MoveNode::MoveNode(Board top) {
    this->curBoard = top;
    this->depthSearched = 0;
    this->parent = nullptr;
    this->next = std::vector<MoveNode*>();
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

std::vector<MoveNode *> MoveNode::getNext() {
    return next;
}

