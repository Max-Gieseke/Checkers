//
// Created by maxgi on 12/6/2023.
//

#include "../include/RandomPlayer.h"

RandomPlayer::RandomPlayer() {
    std::srand(static_cast<unsigned int>(std::time(nullptr)));
}
Move RandomPlayer::GetPlay(const CheckerBoard &board) {
    std::vector<Move> moves = JumpTree::possibleMoves(board);
    int randomIdx = rand() % moves.size();
    return moves[randomIdx];
}
