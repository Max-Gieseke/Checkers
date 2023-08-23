//
// Created by maxgi on 8/23/2023.
//

#include "MoveNode.h"

MoveNode::MoveNode() {
    this->curBoard = Board();
    this->depthSearched = 0;
    this->score = 0;
    this->parent = nullptr;
    this->next = vector<MoveNode*>();
}

MoveNode::MoveNode(Board b, int depthSearched, double score, MoveNode* p) {
    this->curBoard = b;
    this->depthSearched = depthSearched;
    this->score = score;
    this->parent = p;
    this->next = vector<MoveNode*>();
}


void MoveNode::addChild(MoveNode * child) {
    this->next.push_back(child);
}

Move MoveNode::getBestMove() {
    return bestMove;
}

Board MoveNode::getBoard() {
    return curBoard;
}

int MoveNode::getDepth() {
    return this->depthSearched;
}

MoveNode::MoveNode(Board top) {
    this->curBoard = top;
    this->depthSearched = 0;
    this->parent = nullptr;
    this->next = vector<MoveNode*>();
}

