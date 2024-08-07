//
// Created by maxgi on 10/31/2023.
//

#include "../include/CheckerBoard.h"



CheckerBoard::CheckerBoard() {
    whiteKings = 0;
    blackKings = 0;
    whitePieces = 0;
    whitePieces = whitePieces | 0xFFF << 20;
    blackPieces = 0;
    blackPieces = blackPieces | 0xFFF;
    currentPlayer = 1;  //black starts
}

small CheckerBoard::getPiece(small square) const {
    if (blackPieces & (1 << square)) {
        return 1;
    }
    else if (whitePieces & (1 << square)) {
        return 2;
    }
    else if (blackKings & (1 << square)) {
        return 3;
    }
    else if (whiteKings & (1 << square)) {
        return 4;
    }
    return 0;
}

small CheckerBoard::getColor(small piece) {
    if (piece == 1 || piece == 3) {
        return 1;
    }
    else if (piece == 2 || piece == 4) {
        return 0;
    }
    return -1;
}

int CheckerBoard::finalJump(small start, small capt) {
    int sub = start - capt;
    //Even row is 0, odd row is 1
    int t = capt % 8;
    if (t == 0 || t == 7) {
        return 64;
    }
    small even = (start / 4) % 2;
    if (sub == 3 || sub == 5) {
        return capt - 4;
    }
    else if (sub == 4) {
        if (even == 0) {
            return capt - 3;
        }
        else {
            return capt - 5;
        }
    }
    else if (sub == -3 || sub == -5) {
        return capt + 4;
    }
    else {
        if (even == 0) {
            return capt + 5;
        }
        else {
            return capt + 3;
        }
    }
}

CheckerBoard CheckerBoard::doSingleJump(small start, small end, small remove, bool &newKing) {
    CheckerBoard cBoard = *this;
    newKing = cBoard.movePiece(start, end);
    cBoard.removePiece(remove);
    return cBoard;
}

double CheckerBoard::scoreBoard(const Scores& points) const {
    float curBlack = 0;
    float curWhite = 0;
    for (int i = 0; i < 32; i ++) {
        //black pawn
        small curPiece = getPiece(i);
        if (curPiece == 1) {
            curBlack += points.pawnVal;
            curBlack += points.rankBonus * (i / 4);
        }
            //white pawn
        else if (curPiece == 2) {
            curWhite += points.pawnVal;
            curWhite += points.rankBonus * (7 - (i / 4));
        }
            //black king
        else if (curPiece == 3) {
            curBlack += points.kingVal;
        }
            //white king
        else if (curPiece == 4) {
            curWhite += points.kingVal;
        }
    }
    if (curBlack == 0) {
        return -points.win;
    }
    if (curWhite == 0) {
        return points.win;
    }
    return curBlack - curWhite;
}

CheckerBoard &CheckerBoard::operator=(const CheckerBoard &other) {
    if (this != &other) {
        this->whitePieces = other.whitePieces;
        this->blackPieces = other.blackPieces;
        this->whiteKings = other.whiteKings;
        this->blackKings = other.blackKings;

        this->currentPlayer = other.currentPlayer;
    }
    return *this;
}

bool CheckerBoard::gameOver() const{
    return (((getPieceSet(1) == 0) && (getPieceSet(3) == 0)) ||
            ((getPieceSet(2) == 0) && (getPieceSet(4) == 0)));
}

std::ostream &operator<<(std::ostream& out, CheckerBoard board) {
    int i = 28;
    while (i >= 0) {
        if (i % 8 == 4) {
            out << "   ";
        }
        if (board.getPiece(i) == 0) {
            out << "___";
        }
        else if (board.getPiece(i) == 1) {
            out << "_b_";
        }
        else if (board.getPiece(i) == 2) {
            out << "_w_";
        }
        else if (board.getPiece(i) == 3) {
            out << "_B_";
        }
        else {
            out << "_W_";
        }
        out << "   ";
        if (i % 4 == 3) {
            out << std::endl;
            i -= 7;
        }
        else {
            i++;
        }
    }
    if (board.getPlayer() == 0) {
        out << "White to play\n";
    }
    else {
        out << "Black to play\n";
    }
    return out;
}

bool CheckerBoard::movePiece(small start, small end) {
    small kind = getPiece(start);
    if (kind == 1) {
        blackPieces = blackPieces & ~(1 << start);
        if (end > 27) {
            blackKings = blackKings | (1 << end);
            return true;
        }
        blackPieces = blackPieces | (1 << end);
    }
    else if (kind == 2) {
        whitePieces = whitePieces & ~(1 << start);
        if (end < 4) {
            whiteKings = whiteKings | (1 << end);
            return true;
        }
        whitePieces = whitePieces | (1 << end);
    }
    else if (kind == 3) {
        blackKings = blackKings & ~(1 << start);
        blackKings = blackKings | (1 << end);
    }
    else {
        whiteKings = whiteKings & ~(1 << start);
        whiteKings = whiteKings | (1 << end);
    }
    return false;
}

void CheckerBoard::removePiece(small square) {
    if (blackPieces & (1 << square)) {
        blackPieces = blackPieces & ~(1 << square);
    }
    else if (whitePieces & (1 << square)) {
        whitePieces = whitePieces & ~(1 << square);
    }
    else if (blackKings & (1 << square)) {
        blackKings = blackKings & ~(1 << square);
    }
    else {
        whiteKings = whiteKings & ~(1 << square);
    }
}

small CheckerBoard::getPlayer() const {
    return currentPlayer;
}

void CheckerBoard::switchPlayer() {
    currentPlayer = 1 - currentPlayer;
}

int CheckerBoard::getPieceSet(int pieceType) const {
    if (pieceType == 1) {
        return blackPieces;
    }
    else if (pieceType == 2) {
        return whitePieces;
    }
    else if (pieceType == 3) {
        return blackKings;
    }
    return whiteKings;
}

CheckerBoard CheckerBoard::doTurn(const Move& move) const {
    CheckerBoard nBoard = *this;
    nBoard.movePiece(move.getStart(), move.getEnd());
    for (const small& sq : move.getRemove()) {
        nBoard.removePiece(sq);
    }
    nBoard.switchPlayer();
    return nBoard;
}

void CheckerBoard::updateBoard(const Move& move) {
    movePiece(move.getStart(), move.getEnd());
    for (const small& sq : move.getRemove()) {
        removePiece(sq);
    }
    switchPlayer();
}


bool CheckerBoard::operator==(const CheckerBoard& other) {
    if (this->whitePieces != other.whitePieces) {return false;}
    if (this->blackPieces != other.blackPieces) {return false;}
    if (this->whiteKings != other.whiteKings) {return false;}
    if (this->blackKings != other.blackKings) {return false;}
    return this->currentPlayer == other.currentPlayer;
}
