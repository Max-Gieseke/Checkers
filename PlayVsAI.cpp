//
// Created by maxgi on 8/23/2023.
//

#include "MoveTree.h"
#include "cstdlib"

int main(){
    Board::initializeMaps();
    MoveTree player = MoveTree();
    player.exploreTree(6);
    double eval = 0;
    std::cout << player.getRoot()->getBoard();
    int tmp;
    while(eval < 99 && eval > -99){
        tmp = -1;
        while(tmp < 0 || tmp > player.getRoot()->getNext().size()){
            std::cout << "Choose an option:\n";
            for(int i = 0; i < player.getRoot()->getNext().size(); i++){
                std::cout << i << ".) " << player.getRoot()->getNext()[i]->getLastMove();
            }
            std::cin >> tmp;
        }
        player.updateRoot(player.getRoot()->getNext()[tmp]->getLastMove());
        std::cout << player.getRoot()->getBoard();
        eval = player.exploreTree(8);
        player.updateRoot(player.getRoot()->getBestMove());
        std::cout << "------------------------------------\n";
        std::cout << "Evaluation: " << eval << std::endl;
        std::cout << player.getRoot()->getBoard();
    }
}
