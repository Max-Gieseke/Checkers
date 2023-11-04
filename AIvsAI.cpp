//
// Created by maxgi on 8/23/2023.
//
#include <iostream>
#include "MoveTree.h"

int main(){
        MoveTree player = MoveTree();
        double eval = 0;
        std::cout << player.getRoot()->getBoard();
        int move = 0;
        while(eval < 99 && eval > -99){
            move++;
            eval = player.exploreTree(6);
            std::cout << "Tree size: " << player.getTreeSize() << std::endl;
            std::cout << "Move "<< move << " Evaluation: " << eval << std::endl;
//            std::cout << "Moves:\n";
//            for(auto m : player.getRoot()->getNext()){
//                std::cout << m->getLastMove();
//            }
            player.updateRoot(player.getRoot()->getBestMove());
            std::cout << player.getRoot()->getBoard();
            eval = player.exploreTree(6);
            player.updateRoot(player.getRoot()->getBestMove());
            std::cout << "------------------------------------\n";
            std::cout <<"Move " << ++move<< " Evaluation: " << eval << std::endl;
            std::cout << player.getRoot()->getBoard() << std::endl << std::endl;
        }
}