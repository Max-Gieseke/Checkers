//
// Created by maxgi on 8/23/2023.
//
#include <iostream>
#include "../include/AiPlayer.h"
#include "../include/MCPlayer.h"
int main(){
    AiPlayer ai = AiPlayer(8);
    CheckerBoard board;
    double eval = 0;
    std::cout << board;
    std::cout << board.scoreBoard(ai.getScoring()) << std::endl;
    std::cout << "------------------------------------\n";
    int move = 0;
        while(eval < 99 && eval > -99){
            std::cout << "------------------------------------\n";
            ai.completeTurn(board);
            move++;
            std::cout << board;
            eval = board.scoreBoard(ai.getScoring());
            //only black can win on its turn
            std::cout << "Board above is " << eval << std::endl;
            if(board.gameOver()){
                std::cout << "black won\n";
                return 0;
            }
            //White Move
            ai.completeTurn(board);
            std::cout << board;
            eval = board.scoreBoard(ai.getScoring());
            std::cout << "Board above is " << eval << std::endl;
            if(board.gameOver()){
                std::cout << "white won\n";
                return 0;
            }
            std::cout << "------------------------------------\n";

        }
}