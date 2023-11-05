//
// Created by maxgi on 8/22/2023.
//
#include <iostream>
#include "MoveTree.h"
#include "Board.h"
#include <chrono>
#include "Move.h"

int main(){
   // MoveTree start = MoveTree(Board::randomBoard());
    CheckerBoard board;
    std::cout << board;

    auto begin = std::chrono::high_resolution_clock::now();
    std::pair<double, Move> temp = MoveTree::exploreMoves(8, board);
    auto end = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end - begin).count();

    std::cout << "Position Evaluation: " << temp.first << std::endl;
    std::cout << "Best move\n" << temp.second;
    std::cout << "Time taken: " << duration << " microseconds (" << duration / 1000000.0 << " seconds)\n";
    board = CheckerLogic::doTurn(temp.second, board);
    std::cout << board;
    temp = MoveTree::exploreMoves(8, board);
    std::cout << "Score: " << temp.first << std::endl;
    std::cout << "Move: " << temp.second;
    board = CheckerLogic::doTurn(temp.second, board);
    std::cout << board;
    std::cout << "Actual score: " << CheckerLogic::scoreBoard(board);

    return 0;
}