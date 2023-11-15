//
// Created by maxgi on 11/15/2023.
//

#ifndef CHECKERS_PLAYER_H
#define CHECKERS_PLAYER_H
#include "CheckerLogic.h"

class Player {
public:
    virtual Move getPlay(const CheckerBoard&) = 0;
    virtual void doTurn(CheckerBoard& board) {
        Move m = getPlay(board);
        board = CheckerLogic::doTurn(m, board);
    }
};


#endif //CHECKERS_PLAYER_H
