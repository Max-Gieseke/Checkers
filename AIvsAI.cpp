//
// Created by maxgi on 8/23/2023.
//
#include <iostream>
#include "CheckerLogic.h"

int main(){
    int depth = 6;
    CheckerBoard board;
    double eval = 0;
    std::cout << board;
    std::cout << "------------------------------------\n";
    int move = 0;
        while(eval < 99 && eval > -99){
            std::pair<double, Move> tmp;
            move++;
            // Black move
            tmp = CheckerLogic::exploreMoves(depth, board);
            std::cout << "Move "<< move << " Evaluation: " << tmp.first << std::endl;
            board = CheckerLogic::doTurn(tmp.second, board);
            std::cout << board;
            eval = CheckerLogic::scoreBoard(board);
            //only black can win on its turn
            std::cout << "Board above is " << eval << std::endl;
            if(move == 91){
                std::cout << "Is game over: " << CheckerLogic::gameOver(board) << std::endl;
            }
            if(CheckerLogic::gameOver(board)){
                std::cout << "black won\n";
                return 0;
            }
            if(tmp.first > 200){
                std::cout << "Bad score\n";
                return 0;
            }
            //White Move
            tmp = CheckerLogic::exploreMoves(depth, board);
            std::cout <<"Move " << ++move<< " Evaluation: " << tmp.first << std::endl;
            board = CheckerLogic::doTurn(tmp.second, board);
            std::cout << board;
            eval = CheckerLogic::scoreBoard(board);
            std::cout << "Board above is " << eval << std::endl;
            if(CheckerLogic::gameOver(board)){
                std::cout << "white won\n";
                return 0;
            }
            std::cout << "------------------------------------\n";
            if(tmp.first > 200){
                std::cout << "Bad score\n";
                return 0;
            }
        }
}