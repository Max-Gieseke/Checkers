//
// Created by maxgi on 11/15/2023.
//

#ifndef CHECKERS_PLAYER_H
#define CHECKERS_PLAYER_H
#include "CheckerBoard.h"
#include "JumpTree.h"
#include "TranspositionTable.h"

class Player {
public:
    virtual Move getPlay(const CheckerBoard&, TranspositionTable&) = 0;
    virtual void completeTurn(CheckerBoard& board, TranspositionTable& pastPositions) {
        Move m = getPlay(board, pastPositions);
        //std::cout << m;
        board = board.doTurn(m);
        if (pastPositions.isIn(board, 0)) {
            pastPositions.addValue(board, pastPositions.getDepth(board) + 1, 0);
        }
        else {
            pastPositions.addValue(board, 1, 0);
        }
    }

    static bool doneGame(const CheckerBoard& board, TranspositionTable& pastPositions) {
        return JumpTree::possibleMoves(board).empty() || (pastPositions.getDepth(board) >= 3);
    }

    static int playGame(Player& p1, Player& p2) {
        CheckerBoard board;
        TranspositionTable pastPositions;
        int turns = 0;
        while (turns < 150) {
            p1.completeTurn(board, pastPositions);
            if (board.gameOver() || doneGame(board, pastPositions)) {
                //player 1 wins
                return 1;
            }

            p2.completeTurn(board, pastPositions);
            if (board.gameOver()|| doneGame(board, pastPositions)) {
                //player 2 wins
                return -1;
            }
            turns+= 2;

        }
        return 0;
    }
};


#endif //CHECKERS_PLAYER_H
