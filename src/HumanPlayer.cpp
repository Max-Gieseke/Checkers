//
// Created by maxgi on 11/15/2023.
//

#include "../include/HumanPlayer.h"

Move HumanPlayer::getPlay(const CheckerBoard& board) {
    int tmp = -1;
    std::vector<Move> moves = CheckerLogic::possibleMoves(board);
    while(tmp < 0 || tmp > moves.size()){
        std::cout << "Choose an option:\n";
        for(int i = 0; i < moves.size(); i++){
            std::cout << i << ".) " << moves[i];
        }
        std::cin >> tmp;
    }
    return moves[tmp];
}
