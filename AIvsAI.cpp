//
// Created by maxgi on 8/23/2023.
//
#include <iostream>
#include "CheckerLogic.h"
#include "AiPlayer.h"
int main(){
    AiPlayer ai = AiPlayer(12);
    CheckerBoard board;
    double eval = 0;
    std::cout << board;
    std::cout << "------------------------------------\n";
    int move = 0;
        while(eval < 99 && eval > -99){
            std::cout << "------------------------------------\n";
            ai.doTurn(board);
            move++;
            std::cout << board;
            eval = CheckerLogic::scoreBoard(board);
            //only black can win on its turn
            std::cout << "Board above is " << eval << std::endl;
            if(CheckerLogic::gameOver(board)){
                std::cout << "black won\n";
                return 0;
            }
            //White Move
            ai.doTurn(board);
            std::cout << board;
            eval = CheckerLogic::scoreBoard(board);
            std::cout << "Board above is " << eval << std::endl;
            if(CheckerLogic::gameOver(board)){
                std::cout << "white won\n";
                return 0;
            }
            std::cout << "------------------------------------\n";

        }
}