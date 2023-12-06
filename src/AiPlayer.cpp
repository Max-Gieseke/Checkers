//
// Created by maxgi on 11/15/2023.
//

#include <utility>

#include "../include/AiPlayer.h"

AiPlayer::AiPlayer() {
    depth = 8;
}

AiPlayer::AiPlayer(int depth) {
    this->depth = depth;
}

AiPlayer::AiPlayer(int depth, Scores scores) {
    scoring = std::move(scores);
    this->depth = depth;
}

Move AiPlayer::getPlay(const CheckerBoard& board) {
    std::pair<float, Move> tmp = exploreMoves(depth, board);
    std::cout << "Move "<< tmp.second << " Evaluation: " << tmp.first << std::endl;
    return tmp.second;
}

float AiPlayer::explore(int left, CheckerBoard board, float alpha, float beta){
    if (left == 0) {
        return handleExpanded(board);
    }
    float multiply = (2 * board.getPlayer() - 1);
    if (board.gameOver()) {
        //Current player lost, so inverse multiply
        return  -multiply * scoring.win + multiply * left;
    }
    std::vector<Move> moves = JumpTree::possibleMoves(board);
    if (moves.empty()) {
        return  -multiply * scoring.win + multiply * left;
    }
    float best = FLT_MIN;
    for(const auto& m : moves) {
        CheckerBoard tmpBoard = board.doTurn(m);
        float val;
        if(pastMoves.isIn(tmpBoard, left)) {
            val = pastMoves.getEvaluation(tmpBoard);
        }
        else {
            val = explore(left - 1, tmpBoard, alpha, beta);
        }

        best = std::max(best, val * multiply);
        if (multiply == 1){
            alpha = std::max(alpha, best);
        }
        else {
            beta = std::min(beta, best * multiply);
        }

        if(beta <= alpha) {
            break;
        }

    }
    return best * multiply;
}

float AiPlayer::handleExpanded(CheckerBoard board){
    float multiply = 2 * board.getPlayer() - 1; //if 1, then black's turn, -1 then white's turn
    std::vector<Move> jumpMoves = JumpTree::possibleMoves(board);
    if(jumpMoves.empty()){
        return -multiply * scoring.win;
    }
    else {
        if (jumpMoves[0].isCapture()){
            float max = -FLT_MAX;
            for(const auto& m : jumpMoves){
                CheckerBoard tmpBoard = board.doTurn(m);
                float score = handleExpanded(tmpBoard) * multiply;
                if(score > max){
                    max = score;
                }
            }
            return max;
        }
        else {
            return board.scoreBoard(scoring);
        }
    }
}

std::pair<float, Move> AiPlayer::exploreMoves(int left, CheckerBoard board) {
    //When first passed in, we should not have 0 moves or a game over state
    if(left == 0 || board.gameOver()){
        return {board.scoreBoard(scoring), Move()};
    }
    std::vector<Move> moves = JumpTree::possibleMoves(board);
     //if 1, then black's turn, -1 then white's turn
    int multiply = 2 * board.getPlayer() - 1;
    Move bestMove;
    float alpha = -FLT_MAX;
    float beta = FLT_MAX;
    float best = -FLT_MAX;
    for(const auto& m : moves) {
        CheckerBoard tmpBoard = board.doTurn(m);
        float val;
        if(pastMoves.isIn(tmpBoard, left)) {
            val = pastMoves.getEvaluation(tmpBoard);
        }
        else {
            val = explore(left - 1, tmpBoard, alpha, beta);
        }
//            std::cout << m;
//            std::cout << val << std::endl;
        if (val * multiply > best){
            best = val * multiply;
            bestMove = m;
        }

    }
    return {best * multiply, bestMove};
}

Scores AiPlayer::getScoring() const {
    return scoring;
}

AiPlayer& AiPlayer::operator=(const AiPlayer& other) {
    if(this != &other){
        this->scoring = other.scoring;
        this->depth = other.depth;
        this->pastMoves = other.pastMoves;
    }
    return *this;
}

AiPlayer::AiPlayer(const AiPlayer &other) {
    if(this != &other){
        this->scoring = other.scoring;
        this->depth = other.depth;
        this->pastMoves = other.pastMoves;
    }
}
