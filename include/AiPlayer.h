//
// Created by maxgi on 11/15/2023.
//

#ifndef CHECKERS_AIPLAYER_H
#define CHECKERS_AIPLAYER_H
#include "Player.h"
#include "TranspositionTable.h"
#include "JumpTree.h"
#include "Scores.h"


class AiPlayer : public Player {
private:
    Scores scoring;
    TranspositionTable pastMoves;
    int depth;
    Scores values;
public:
    AiPlayer();
    AiPlayer(int);
    Move getPlay(const CheckerBoard&);
    double explore(int left, CheckerBoard board, double alpha, double beta);
    double handleExpanded(CheckerBoard board);
    std::pair<double, Move>exploreMoves(int, CheckerBoard);
    Scores getScoring();
};


#endif //CHECKERS_AIPLAYER_H
