//
// Created by maxgi on 8/22/2023.
//

#include "MoveTree.h"

MoveTree::MoveTree() {
   root = new MoveNode();
   exploredMoves = TranspositionTable();
}

MoveTree::MoveTree(Board top) {
    root = new MoveNode(top);
    exploredMoves = TranspositionTable();
}

MoveTree::MoveTree(Board b, int depthSearched, double score, MoveNode* p) {
    root = new MoveNode(b, depthSearched, score, p, Move());
    exploredMoves = TranspositionTable();
}

MoveTree::~MoveTree() {
    delete root;
}

double MoveTree::exploreTree(int moves) {
    return exploreMoves(moves, root);
}

double MoveTree::explore(int left, MoveNode* node) {
    if(left <= 0){
        node->score = node->curBoard.scoreBoard();
        return node->score;
    }

    std::vector<Move> moves = node->curBoard.possibleMoves();
    double max = -INT32_MAX;
    int multiply = 1;
    if(node->curBoard.getPlayer() == 0){
        multiply = -1;
    }
    Move best;
    for(const Move& m : moves){
        double score;
        Board b = Board::doMove(m, node->curBoard);
        MoveNode* newChild = new MoveNode(b, left, 0, node, m);
        node->addChild(newChild);
        score = explore(left - 1, node->next.back());
        if(multiply * score > max){
            max = multiply * score;
            best = m;
        }
    }
    node->score = multiply * max;
    node->bestMove = best;
    return node->score;
}

double MoveTree::exploreMoves(int left, MoveNode* node) {
    if(left <= 0){
        node->score = node->curBoard.scoreBoard();
        return node->score;
    }
    std::vector<Move> moves = node->curBoard.possibleMoves();
    double max = -INT32_MAX;
    int multiply = 1;
    if(node->curBoard.getPlayer() == 0){
        multiply = -1;
    }
    Move best;
    for(const auto& m : moves){
        double score;
        Board b = Board::doMove(m, node->curBoard);
        if(exploredMoves.isIn(b, left)){
            node->addChild(exploredMoves.getNode(b));
            score = node->next.back()->score;
        }
        else{
            MoveNode* newChild = new MoveNode(b, left, 0, node, m);
            node->addChild(newChild);
            score = exploreMoves(left - 1, node->next.back());
            exploredMoves.addValue(newChild);
        }

        if(multiply * score > max){
            max = multiply * score;
            best = m;
        }
    }
    node->score = multiply * max;
    node->bestMove = best;
    return node->score;
}


void MoveTree::addElem(MoveNode* check) {
    //int key = exploredMoves.computeHash(check->curBoard);
    exploredMoves.addValue(check);

}

MoveNode* MoveTree::getRoot() {
    return root;
}

void MoveTree::updateRoot(const Move& lastMove) {
    for(auto & node : root->next){
        if(node->lastMove.equals(lastMove)){
            root = node;
            break;
        }
    }
}
