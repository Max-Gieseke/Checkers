//
// Created by maxgi on 11/15/2023.
//

#ifndef CHECKERS_AIPLAYER_H
#define CHECKERS_AIPLAYER_H
#include "Player.h"
#include "TranspositionTable.h"
#include "JumpTree.h"
#include "Scores.h"
#include <cfloat>


class AiPlayer : public Player {
private:
    Scores scoring;
    TranspositionTable pastMoves;
    int depth;
public:
    AiPlayer();
    explicit AiPlayer(int);
    AiPlayer(int, Scores);
    Move getPlay(const CheckerBoard&, TranspositionTable&) override;
    double explore(int left, CheckerBoard board, double alpha, double beta, TranspositionTable&);
    double handleExpanded(CheckerBoard board, TranspositionTable&);
    std::pair<double, Move>exploreMoves(int, CheckerBoard, TranspositionTable&);
    Scores getScoring() const;
    AiPlayer& operator=(const AiPlayer&);

    AiPlayer(const AiPlayer& player);
};


#endif //CHECKERS_AIPLAYER_H
