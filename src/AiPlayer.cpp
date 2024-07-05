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
    scoring = scores;
    this->depth = depth;
}

Move AiPlayer::getPlay(const CheckerBoard& board, TranspositionTable& pastPositions) {
    std::pair<double, Move> tmp = exploreMoves(depth, board, pastPositions);
    return tmp.second;
}

double AiPlayer::explore(int left, CheckerBoard board, double alpha, double beta, TranspositionTable& pastPositions){
    if (left == 0) {
        return handleExpanded(board, pastPositions);
    }
    double multiply = (2 * board.getPlayer() - 1);
    if (board.gameOver()) {
        //Current player lost, so inverse multiply
        return  -multiply * scoring.win + multiply * left;
    }
    std::vector<Move> moves = JumpTree::possibleMoves(board);
    if (moves.empty()) {
        return  -multiply * scoring.win + multiply * left;
    }
    double best = -INT32_MAX;
    for (const auto& m : moves) {
        CheckerBoard tmpBoard = board.doTurn(m);
        double val;
        if (pastPositions.getDepth(tmpBoard) >= 3) { //draw
            val = 0;
        }
        else if (pastMoves.isIn(tmpBoard, left)) {
            val = pastMoves.getEvaluation(tmpBoard);
        }
        else {
            val = explore(left - 1, tmpBoard, alpha, beta, pastPositions);
            pastMoves.addValue(tmpBoard, left, val);
        }

        best = std::max(best, val * multiply);
        if (multiply == 1) {
            alpha = std::max(alpha, best);
        }
        else {
            beta = std::min(beta, best * multiply);
        }

        if (beta <= alpha) {
            break;
        }

    }
    //remove multiplication
    return best * multiply;
}

double AiPlayer::handleExpanded(CheckerBoard board, TranspositionTable& pastPositions){
    double multiply = 2 * board.getPlayer() - 1; //if 1, then black's turn, -1 then white's turn
    std::vector<Move> jumpMoves = JumpTree::possibleMoves(board);
    if (jumpMoves.empty()) {
        return -multiply * scoring.win;
    }
    else {
        if (jumpMoves[0].isCapture()) {
            double max = -INT32_MAX;
            for (const auto& m : jumpMoves) {
                CheckerBoard tmpBoard = board.doTurn(m);
                double score = 0;
                if (pastPositions.getDepth(tmpBoard) < 3) {
                    score = handleExpanded(tmpBoard, pastPositions);
                }
                if (score * multiply > max) {
                    max = score * multiply;
                }
            }
            //remove multiplicity
            return max * multiply;
        }
        else {
            return board.scoreBoard(scoring);
        }
    }
}

std::pair<double, Move> AiPlayer::exploreMoves(int left, CheckerBoard board, TranspositionTable& pastPositions) {
    //When first passed in, we should not have 0 moves or a game over state
    if (left == 0 || board.gameOver()) {
        return {board.scoreBoard(scoring), Move()};
    }
    std::vector<Move> moves = JumpTree::possibleMoves(board);
     //if 1, then black's turn, -1 then white's turn
    int multiply = 2 * board.getPlayer() - 1;
    Move bestMove;
    double alpha = -FLT_MAX;
    double beta = FLT_MAX;
    double best = -FLT_MAX;
    for (const auto& m : moves) {
        CheckerBoard tmpBoard = board.doTurn(m);
        double val;
        if (pastPositions.getDepth(tmpBoard) >= 3) {
            val = 0;
        }
        else if (pastMoves.isIn(tmpBoard, left)) {
            val = pastMoves.getEvaluation(tmpBoard);
        }
        else {
            val = explore(left - 1, tmpBoard, alpha, beta, pastPositions);
            pastMoves.addValue(tmpBoard, left, val);
        }
        if (val * multiply > best) {
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
    if (this != &other) {
        this->scoring = other.scoring;
        this->depth = other.depth;
        this->pastMoves = other.pastMoves;
    }
    return *this;
}

AiPlayer::AiPlayer(const AiPlayer &other) {
    if (this != &other) {
        this->scoring = other.scoring;
        this->depth = other.depth;
        this->pastMoves = other.pastMoves;
    }
}
