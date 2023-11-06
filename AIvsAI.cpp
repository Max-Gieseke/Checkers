//
// Created by maxgi on 8/23/2023.
//
#include <iostream>
#include "CheckerLogic.h"

int main(){
    int depth = 4;
    CheckerBoard board;
    double eval = 0;
    std::cout << board;
    std::cout << "------------------------------------\n";
    int move = 0;
        while(eval < 99 && eval > -99 && move < 40){
            std::pair<double, Move> tmp;
            move++;

            // Black move
            tmp = CheckerLogic::exploreMoves(depth, board);
            std::cout << "Move "<< move << " Evaluation: " << tmp.first << std::endl;
            board = CheckerLogic::doTurn(tmp.second, board);
            std::cout << board;
            eval = CheckerLogic::scoreBoard(board);
            std::cout << "Board above is " << eval << std::endl;

            //White Move
            tmp = CheckerLogic::exploreMoves(depth, board);
            std::cout <<"Move " << ++move<< " Evaluation: " << tmp.first << std::endl;
            board = CheckerLogic::doTurn(tmp.second, board);
            std::cout << board;
            eval = CheckerLogic::scoreBoard(board);
            std::cout << "Board above is " << eval << std::endl;
            std::cout << "------------------------------------\n";
        }
}