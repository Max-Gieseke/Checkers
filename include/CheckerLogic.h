//
// Created by maxgi on 10/31/2023.
//

#ifndef CHECKERS_CHECKERLOGIC_H
#define CHECKERS_CHECKERLOGIC_H

#include "Move.h"
#include "CheckerBoard.h"
#include "CheckerMoveMaps.h"
#include "JumpTree.h"
#include "TranspositionTable.h"
#include "queue"
class CheckerLogic {
private:
    /**
     * Determines what square a jump would land on, does not bound check
     * @return an int representing the ending square of a single jump
     */
    static int finalJump(small, small);
    static small getColor(small);
    static std::vector<std::pair<small, small>> singleJump(small, const CheckerBoard&);
    static std::vector<Move> getJumps(small, const CheckerBoard&);
public:
    static std::vector<Move> possibleMoves(const CheckerBoard& board);
    static CheckerBoard doMove(const Move&, const CheckerBoard&);
    static CheckerBoard doTurn(const Move&, const CheckerBoard&);
    static std::pair<double, Move>exploreMoves(int, CheckerBoard, TranspositionTable&);
    /**
     * Do a single jump on curBoard and return a new board with the completed jump
     * and whether a king was made
     * @param start the square the move started from
     * @param end the square the piece ends up on
     * @param remove the square that should be removed
     * @param curBoard the board that is being used
     * @return a new CheckerBoard with the jump done
     */
    static CheckerBoard doSingleJump(small start, small end, small remove, const CheckerBoard& curBoard, bool& newKing);
    /**
     * Gets most jumps from a list of moves
     * @return the number of jumps a list of moves has
     */
    static small maxJumps(std::vector<Move>);
    static double scoreBoard(const CheckerBoard&);

    static bool gameOver(const CheckerBoard &board);

    static double explore(int left, CheckerBoard board, double alpha, double beta, TranspositionTable&);

    static double handleExpanded(CheckerBoard board);
};


#endif //CHECKERS_CHECKERLOGIC_H
