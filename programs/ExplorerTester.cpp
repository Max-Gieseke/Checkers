//
// Created by maxgi on 8/22/2023.
//
#include <iostream>
#include "../include/CheckerLogic.h"
#include "../include/Board.h"
#include <chrono>
#include "../include/Move.h"
#include "../include/AiPlayer.h"

int main(){
   // MoveTree start = MoveTree(Board::randomBoard());
    CheckerBoard board;
    std::cout << board;
    AiPlayer ai = AiPlayer(11);

    auto begin = std::chrono::high_resolution_clock::now();
    Move m = ai.getPlay(board);
    auto end = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end - begin).count();
    std::cout << "Best move\n" << m;
    std::cout << "Time taken: " << duration << " microseconds (" << duration / 1000000.0 << " seconds)\n";
    ai.doTurn(board);
    std::cout << board;
    return 0;
}