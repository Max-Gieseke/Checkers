//
// Created by maxgi on 11/15/2023.
//

#include "AiPlayer.h"

AiPlayer::AiPlayer() {
    depth = 8;
}

AiPlayer::AiPlayer(int depth) {
    this->depth = depth;
}

Move AiPlayer::getPlay(const CheckerBoard& board) {
    std::pair<double, Move> tmp = CheckerLogic::exploreMoves(depth, board, pastMoves);
    //std::cout << "Move "<< tmp.second << " Evaluation: " << tmp.first << std::endl;
    return tmp.second;
}
