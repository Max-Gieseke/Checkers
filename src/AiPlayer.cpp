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
    //std::cout << "Move "<< tmp.second << " Evaluation: " << tmp.first << std::endl;
    return tmp.second;
}

float AiPlayer::explore(int left, CheckerBoard board, float alpha, float beta){
    int multiply = 1;
    if (board.getPlayer() == 0) {
        multiply = -1;
    }
    if (left == 0){
        return handleExpanded(board);
    }
    if (board.gameOver()){
        if(board.getPlayer() == 0){
            return scoring.winVal - left;
        }
        return -scoring.winVal + left;
    }
    std::vector<Move> moves = JumpTree::possibleMoves(board);
    if(moves.empty()){
        if(board.getPlayer() == 0){
            return scoring.winVal - left;
        }
        return -scoring.winVal + left;
    }
//    int multiply = 1;
//    if (board.getPlayer() == 0) {
//        multiply = -1;
//    }
    float max = -FLT_MAX;
    for(const auto& m : moves){
        float score;
        CheckerBoard tmpBoard = board.doTurn(m);
        if(pastMoves.isIn(tmpBoard, left)){
            score = pastMoves.getEvaluation(tmpBoard);
        }
        else {
            score = explore(left - 1, tmpBoard, alpha, beta)  * multiply;
            pastMoves.addValue(tmpBoard, left, score);
        }
        if(score > max){
            max = score;
        }
        if(multiply == 1) { //trying to maximize
            alpha = std::max(alpha, score);
            if (alpha >= beta) {
                break;
            }
        }
        else { //trying to minimize
            beta = std::min(beta, score);
            if (beta <= alpha){
                break;
            }
//            else {
//                std::cout << "Not here\n";
//            }
        }
    }
    return max;

}

float AiPlayer::handleExpanded(CheckerBoard board){
    int multiply = 1; //if 1, then black's turn, -1 then white's turn
    if(board.getPlayer() == 0){
        multiply = -1;
    }
    std::vector<Move> jumpMoves = JumpTree::possibleMoves(board);
    if(jumpMoves.empty()){
        return multiply * -scoring.winVal;
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
        if(board.getPlayer() == 0){
            return {100, Move()};
        }
        return {board.scoreBoard(scoring), Move()};
    }
    std::vector<Move> moves = JumpTree::possibleMoves(board);
    int multiply = 1; //if 1, then black's turn, -1 then white's turn
    if(board.getPlayer() == 0){
        multiply = -1;
    }
    Move best;
    float max = -FLT_MAX;
    float alpha = -FLT_MAX;
    float beta = FLT_MAX;
    for(const auto& m : moves){
        float score;
        CheckerBoard tmpBoard = board.doTurn(m);
        if(pastMoves.isIn(tmpBoard, left)){
            score = pastMoves.getEvaluation(tmpBoard);
        }
        else {
            score = explore(left - 1, tmpBoard, alpha, beta)  * multiply;
            pastMoves.addValue(tmpBoard, left, score);
        }

//        if(board.getPlayer() == 0){
//            std::cout << "Score:" << score << " " << m;
//        }

        if(score > max){
            max = score;
            best = m;
        }
        if(multiply == 1) { //trying to maximize
            alpha = std::max(alpha, score);
            if (alpha >= beta) {
                break;
            }
        }
        else { //trying to maximize
            beta = std::min(beta, score);
            if (beta <= alpha){
                break;
            }
        }

    }
    //std::cout << "Best: " << best;
    return {max, best};
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
