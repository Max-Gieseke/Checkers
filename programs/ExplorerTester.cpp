//
// Created by maxgi on 8/22/2023.
//
#include <iostream>
#include <chrono>
#include "../include/Move.h"
#include "../include/AiPlayer.h"
#include "../include/MCPlayer.h"

int main() {
   // MoveTree start = MoveTree(Board::randomBoard());
    srand(std::time(nullptr));
    CheckerBoard board;
    std::cout << board;
    MCPlayer ai = MCPlayer(1, 1);
    TranspositionTable past;
    auto begin = std::chrono::high_resolution_clock::now();
    Move m = ai.getPlay(board, past);
    m = ai.getPlay(board, past);
    m = ai.getPlay(board, past);
    auto end = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end - begin).count();
    std::cout << "Best move\n" << m;
    std::cout << "Time taken: " << duration << " microseconds (" << duration / 1000000.0 << " seconds)\n(" << duration / (3 * 1000000.0) << ") average\n";
    return 0;
}