//
// Created by maxgi on 8/23/2023.
//

#include "CheckerLogic.h"
#include "cstdlib"
#include "AiPlayer.h"
#include "HumanPlayer.h"

int main(){
    HumanPlayer human;
    AiPlayer ai = AiPlayer(12);
    CheckerBoard board;
    double eval = 0;
    std::cout << board;
    std::pair<double, Move> temp;
    int tmp;
    while(eval < 99 && eval > -99){
        human.doTurn(board);
        std::cout << board;
        if(CheckerLogic::gameOver(board)){
            std::cout << "You win!\n";
            break;
        }
        ai.doTurn(board);
        std::cout << "------------------------------------\n";
        std::cout << "Evaluation: " << CheckerLogic::scoreBoard(board) << std::endl;
        std::cout << board;
        if(CheckerLogic::gameOver(board)){
            std::cout << "You lost\n";
            break;
        }
    }
}
