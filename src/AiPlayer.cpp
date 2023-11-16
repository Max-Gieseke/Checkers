//
// Created by maxgi on 11/15/2023.
//

#include "../include/AiPlayer.h"

AiPlayer::AiPlayer() {
    depth = 8;
}

AiPlayer::AiPlayer(int depth) {
    this->depth = depth;
}

Move AiPlayer::getPlay(const CheckerBoard& board) {
    std::pair<double, Move> tmp = exploreMoves(depth, board);
    //std::cout << "Move "<< tmp.second << " Evaluation: " << tmp.first << std::endl;
    return tmp.second;
}

double AiPlayer::explore(int left, CheckerBoard board, double alpha, double beta){
    int multiply = 1;
    if (board.getPlayer() == 0) {
        multiply = -1;
    }
    if (left == 0){
        return handleExpanded(board);
    }
    if (board.gameOver()){
        if(board.getPlayer() == 0){
            return 100 - left;
        }
        return -100 + left;
    }
    std::vector<Move> moves = JumpTree::possibleMoves(board);
    if(moves.empty()){
        if(board.getPlayer() == 0){
            return 100 - left;
        }
        return -100 + left;
    }
//    int multiply = 1;
//    if (board.getPlayer() == 0) {
//        multiply = -1;
//    }
    double max = -INT32_MAX;
    for(const auto& m : moves){
        double score;
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

double AiPlayer::handleExpanded(CheckerBoard board){
    int multiply = 1; //if 1, then black's turn, -1 then white's turn
    if(board.getPlayer() == 0){
        multiply = -1;
    }
    std::vector<Move> jumpMoves = JumpTree::possibleMoves(board);
    if(jumpMoves.empty()){
        return multiply * -100;
    }
    else {
        if (jumpMoves[0].isCapture()){
            double max = -INT32_MAX;
            for(const auto& m : jumpMoves){
                CheckerBoard tmpBoard = board.doTurn(m);
                double score = handleExpanded(tmpBoard) * multiply;
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

std::pair<double, Move> AiPlayer::exploreMoves(int left, CheckerBoard board) {
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
    double max = -INT32_MAX;
    double alpha = -INT32_MAX;
    double beta = INT32_MAX;
    for(const auto& m : moves){
        double score;
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
    std::cout << "Best: " << best;
    return {max, best};
}

Scores AiPlayer::getScoring() {
    return scoring;
}
