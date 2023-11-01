//
// Created by maxgi on 8/23/2023.
//
#include <iostream>
#include "MoveTree.h"

int main(){
        MoveTree player = MoveTree();
        double eval = player.exploreTree(8);
        std::cout << player.getRoot()->getBoard();
        int move = 0;
        while(eval < 99 && eval > -99){
            move++;
            eval = player.exploreTree(8);
            std::cout << "Move "<< move << " Evaluation: " << eval << std::endl;
            player.updateRoot(player.getRoot()->getBestMove());
            std::cout << player.getRoot()->getBoard();
            eval = player.exploreTree(8);
            player.updateRoot(player.getRoot()->getBestMove());
            std::cout << "------------------------------------\n";
            std::cout <<"Move " << ++move<< " Evaluation: " << eval << std::endl;
            std::cout << player.getRoot()->getBoard() << std::endl << std::endl;
        }
}