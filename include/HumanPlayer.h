//
// Created by maxgi on 11/15/2023.
//

#ifndef CHECKERS_HUMANPLAYER_H
#define CHECKERS_HUMANPLAYER_H
#include "Player.h"
#include "JumpTree.h"

class HumanPlayer : public Player {
public:
    Move getPlay(const CheckerBoard&);
};


#endif //CHECKERS_HUMANPLAYER_H
