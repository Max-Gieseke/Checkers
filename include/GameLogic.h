//
// Created by maxgi on 10/31/2023.
//

#ifndef CHECKERS_GAMELOGIC_H
#define CHECKERS_GAMELOGIC_H
#include "Board.h"
#include "Move.h"
#include <vector>
class Board;
class GameLogic {
    virtual double scoreBoard(const Board&) = 0;
    virtual std::vector<Move> possibleMoves(const Board&, small);
};


#endif //CHECKERS_GAMELOGIC_H
