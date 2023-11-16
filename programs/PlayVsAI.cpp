//
// Created by maxgi on 8/23/2023.
//

#include "cstdlib"
#include "../include/AiPlayer.h"
#include "../include/HumanPlayer.h"

int main(){
    HumanPlayer human;
    AiPlayer ai = AiPlayer(12);
    CheckerBoard board;
    double eval = 0;
    std::cout << board;
    std::pair<double, Move> temp;
    int tmp;
    while(eval < 99 && eval > -99){
        human.completeTurn(board);
        std::cout << board;
        if(board.gameOver()){
            std::cout << "You win!\n";
            break;
        }
        ai.completeTurn(board);
        std::cout << "------------------------------------\n";
        std::cout << "Evaluation: " << board.scoreBoard(ai.getScoring()) << std::endl;
        std::cout << board;
        if(board.gameOver()){
            std::cout << "You lost\n";
            break;
        }
    }
}
