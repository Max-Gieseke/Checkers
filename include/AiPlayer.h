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
    Move getPlay(const CheckerBoard&) override;
    float explore(int left, CheckerBoard board, float alpha, float beta);
    float handleExpanded(CheckerBoard board);
    std::pair<float, Move>exploreMoves(int, CheckerBoard);
    Scores getScoring() const;
    AiPlayer& operator=(const AiPlayer&);

    AiPlayer(const AiPlayer& player);
};


#endif //CHECKERS_AIPLAYER_H
