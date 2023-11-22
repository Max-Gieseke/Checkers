//
// Created by maxgi on 10/31/2023.
//

#ifndef CHECKERS_CHECKERBOARD_H
#define CHECKERS_CHECKERBOARD_H

#include <vector>
#include "Scores.h"
#include "Move.h"
#include "CheckerMoveMaps.h"
#include "queue"
#include <iostream>

class CheckerBoard {
private:
    int whitePieces;
    int blackPieces;
    int whiteKings;
    int blackKings;
    small currentPlayer;
public:
    CheckerBoard();
    /**
     * Returns what kind of piece is at a square
     * @return 0 for blank, 1 for black piece, 2 for white piece, 3 for black king, 4 for white king
     */
    [[nodiscard]] small getPiece(small) const;
    CheckerBoard& operator=(const CheckerBoard& other);
    friend std::ostream& operator<<(std::ostream&, CheckerBoard);
    bool movePiece(small start, small end);
    [[nodiscard]] small getPlayer() const;
    void removePiece(small square);
    void switchPlayer();
    static small getColor(small);
    static int finalJump(small, small);

    /**
     * Do a single jump on curBoard and return a new board with the completed jump
     * and whether a king was made
     * @param start the square the move started from
     * @param end the square the piece ends up on
     * @param remove the square that should be removed
     * @param curBoard the board that is being used
     * @return a new CheckerBoard with the jump done
     */
    CheckerBoard doSingleJump(small start, small end, small remove, bool& newKing);
    [[nodiscard]] float scoreBoard(const Scores&) const;
    [[nodiscard]] bool gameOver() const;
    void updateBoard(const Move&);
    CheckerBoard doTurn(const Move&) const ;
    [[nodiscard]] int getPieceSet(int pieceType) const;
    bool operator==(const CheckerBoard&);
};


#endif //CHECKERS_CHECKERBOARD_H
