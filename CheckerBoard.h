//
// Created by maxgi on 10/31/2023.
//

#ifndef CHECKERS_CHECKERBOARD_H
#define CHECKERS_CHECKERBOARD_H

#include <vector>
#include "Scores.h"
#include "Move.h"
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
    small getPiece(small) const;
    CheckerBoard& operator=(const CheckerBoard& other);
    friend std::ostream& operator<<(std::ostream&, CheckerBoard);
    bool movePiece(small start, small end);
    small getPlayer() const;
    void removePiece(small square);
    void switchPlayer();

    int getPieceSet(int pieceType) const;
};


#endif //CHECKERS_CHECKERBOARD_H
