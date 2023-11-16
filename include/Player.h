//
// Created by maxgi on 11/15/2023.
//

#ifndef CHECKERS_PLAYER_H
#define CHECKERS_PLAYER_H
#include "CheckerBoard.h"

class Player {
public:
    virtual Move getPlay(const CheckerBoard&) = 0;
    virtual void completeTurn(CheckerBoard& board) {
        Move m = getPlay(board);
        board = board.doTurn(m);
    }
};


#endif //CHECKERS_PLAYER_H
