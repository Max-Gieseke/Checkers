//
// Created by maxgi on 11/15/2023.
//

#ifndef CHECKERS_AIPLAYER_H
#define CHECKERS_AIPLAYER_H
#include "Player.h"
#include "TranspositionTable.h"


class AiPlayer : public Player {
private:
    TranspositionTable pastMoves;
    int depth;
public:
    AiPlayer();
    AiPlayer(int);
    Move getPlay(const CheckerBoard&);
};


#endif //CHECKERS_AIPLAYER_H
