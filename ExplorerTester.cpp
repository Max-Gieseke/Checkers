//
// Created by maxgi on 8/22/2023.
//
#include <iostream>
#include "MoveTree.h"
#include "Board.h"
#include <chrono>
#include "Move.h"

int main(){
    Board::initializeMaps();
   // MoveTree start = MoveTree(Board::randomBoard());
    MoveTree start = MoveTree();
    cout << start.getRoot().getBoard();
    auto begin = std::chrono::high_resolution_clock::now();
    int score = start.exploreTree(6);
    auto end = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end - begin).count();
    cout << "Position Evaluation: " << score << endl;
    cout << "Best move\n" << start.getRoot().getBestMove();
    cout << "Time taken: " << duration << " microseconds (" << duration / 1000000.0 << " seconds)\n";
    start.updateRoot(start.getRoot().getBestMove());
    cout << start.getRoot().getBoard();
    cout << "Score: " << start.exploreTree(6) << endl;
    cout << "Move: " << start.getRoot().getBestMove();
    start.updateRoot(start.getRoot().getBestMove());
    cout << start.getRoot().getBoard();

    return 0;
}