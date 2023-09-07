//
// Created by maxgi on 8/23/2023.
//
#include <iostream>
#include <vector>
#include "Board.h"
#include "MoveTree.h"
#include "cstdlib"

int main(){
    Board::initializeMaps();
    MoveTree player = MoveTree();
    player.exploreTree(6);
    double eval = 0;
    cout << player.getRoot().getBoard();
    int tmp;
    while(eval < 99 && eval > -99){
        tmp = -1;
        while(tmp < 0 || tmp > player.getRoot().getNext().size()){
            cout << "Choose an option:\n";
            for(int i = 0; i < player.getRoot().getNext().size(); i++){
                cout << i << ".) " << player.getRoot().getNext()[i]->getLastMove();
            }
            cin >> tmp;
        }
        player.updateRoot(player.getRoot().getNext()[tmp]->getLastMove());
        cout << player.getRoot().getBoard();
        eval = player.exploreTree(8);
        player.updateRoot(player.getRoot().getBestMove());
        cout << "------------------------------------\n";
        cout << "Evaluation: " << eval << endl;
        cout << player.getRoot().getBoard();
    }
}
