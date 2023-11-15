//
// Created by maxgi on 10/31/2023.
//

#include "CheckerBoard.h"



CheckerBoard::CheckerBoard() {
//    for(int& piece : pieceSet){
//        piece = 0;
//    }
//    pieceSet[0] = pieceSet[0] | 0xFFF;
//    pieceSet[1] = pieceSet[1] | 0xFFF <<20;
    whiteKings = 0;
    blackKings = 0;
    whitePieces = 0;
    whitePieces = whitePieces | 0xFFF << 20;
    blackPieces = 0;
    blackPieces = blackPieces | 0xFFF;
    currentPlayer = 1;  //black starts
}

small CheckerBoard::getPiece(small square) const {
    if(blackPieces & (1 << square)){
        return 1;
    }
    else if(whitePieces & (1 << square)){
        return 2;
    }
    else if(blackKings & (1 << square)){
        return 3;
    }
    else if(whiteKings & (1 << square)){
        return 4;
    }
    return 0;
}

CheckerBoard &CheckerBoard::operator=(const CheckerBoard &other) {
    if(this != &other) {
//        for(int i = 0; i < 4; i++){
//            this->pieceSet[i] = other.pieceSet[i];
//        }
        this->whitePieces = other.whitePieces;
        this->blackPieces = other.blackPieces;
        this->whiteKings = other.whiteKings;
        this->blackKings = other.blackKings;

        this->currentPlayer = other.currentPlayer;
    }
    return *this;
}

std::ostream &operator<<(std::ostream& out, CheckerBoard board) {
    int i = 28;
    while(i >= 0){
        if(i % 8 == 4){
            out << "   ";
        }
        if(board.getPiece(i) == 0){
            out << "___";
        }
        else if(board.getPiece(i) == 1){
            out << "_b_";
        }
        else if(board.getPiece(i) == 2){
            out << "_w_";
        }
        else if(board.getPiece(i) == 3){
            out << "_B_";
        }
        else {
            out << "_W_";
        }
        out << "   ";
        if(i % 4 == 3){
            out << std::endl;
            i -= 7;
        }
        else{
            i++;
        }
    }
    if (board.getPlayer() == 0){
        out << "White to play\n";
    }
    else {
        out << "Black to play\n";
    }
    return out;
}

bool CheckerBoard::movePiece(small start, small end) {
    small kind = getPiece(start);
    if(kind == 1){
        blackPieces = blackPieces & ~(1 << start);
        if(end > 27) {
            blackKings = blackKings | (1 << end);
            return true;
        }
        blackPieces = blackPieces | (1 << end);
    }
    else if(kind == 2){
        whitePieces = whitePieces & ~(1 << start);
        if(end < 4) {
            whiteKings = whiteKings | (1 << end);
            return true;
        }
        whitePieces = whitePieces | (1 << end);
    }
    else if(kind == 3){
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
    if(blackPieces & (1 << square)){
        blackPieces = blackPieces & ~(1 << square);
    }
    else if(whitePieces & (1 << square)){
        whitePieces = whitePieces & ~(1 << square);
    }
    else if(blackKings & (1 << square)){
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
    if(pieceType == 1){
        return blackPieces;
    }
    else if (pieceType == 2){
        return whitePieces;
    }
    else if (pieceType == 3){
        return blackKings;
    }
    return whiteKings;
}
