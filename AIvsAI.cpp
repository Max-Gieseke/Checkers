//
// Created by maxgi on 8/23/2023.
//
#include <iostream>
#include "MoveTree.h"

int main(){
        Board::initializeMaps();
        MoveTree player = MoveTree();
        double eval = player.exploreTree(8);
        cout << player.getRoot().getBoard();
        int move = 0;
        while(eval < 99 && eval > -99){
            move++;
            eval = player.exploreTree(8);
            cout << "Move "<< move << " Evaluation: " << eval << endl;
            player.updateRoot(player.getRoot().getBestMove());
            cout << player.getRoot().getBoard();
            eval = player.exploreTree(8);
            player.updateRoot(player.getRoot().getBestMove());
            cout << "------------------------------------\n";
            cout <<"Move " << ++move<< " Evaluation: " << eval << endl;
            cout << player.getRoot().getBoard() << endl << endl;
        }
}