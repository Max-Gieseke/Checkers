//
// Created by maxgi on 12/6/2023.
//

#ifndef CHECKERS_RANDOMPLAYER_H
#define CHECKERS_RANDOMPLAYER_H

#include "Player.h"
#include "JumpTree.h"


class RandomPlayer : public Player {
    RandomPlayer();
    Move GetPlay(const CheckerBoard& board);

};


#endif //CHECKERS_RANDOMPLAYER_H
