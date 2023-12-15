//
// Created by maxgi on 12/6/2023.
//

#ifndef CHECKERS_RANDOMPLAYER_H
#define CHECKERS_RANDOMPLAYER_H

#include "Player.h"
#include "JumpTree.h"


class RandomPlayer : public Player {
public:
    RandomPlayer();
    Move getPlay(const CheckerBoard& board, TranspositionTable&) override;

};


#endif //CHECKERS_RANDOMPLAYER_H
