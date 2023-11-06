//
// Created by maxgi on 8/23/2023.
//

#include "CheckerLogic.h"
#include "cstdlib"

int main(){
    CheckerBoard board;
    double eval = 0;
    std::cout << board;
    std::pair<double, Move> temp;
    int tmp;
    while(eval < 99 && eval > -99){
        tmp = -1;
        std::vector<Move> moves = CheckerLogic::possibleMoves(board);
        while(tmp < 0 || tmp > moves.size()){
            std::cout << "Choose an option:\n";
            for(int i = 0; i < moves.size(); i++){
                std::cout << i << ".) " << moves[i];
            }
            std::cin >> tmp;
        }
        board = CheckerLogic::doTurn(temp.second, board);
        std::cout << board;
        temp = CheckerLogic::exploreMoves(6, board);
        board = CheckerLogic::doTurn(temp.second, board);
        std::cout << "------------------------------------\n";
        std::cout << "Evaluation: " << temp.first << std::endl;
        std::cout << board;
    }
}
