//
// Created by Max Gieseke on 12/21/2022.
//

#include "Board.h"

std::vector<small> whiteMoveMap[32];
std::vector<small> blackMoveMap[32];
std::vector<small> kingMoveMap[32];

Board::Board(){
    // Initialize squares to starting values
    for(int i = 0; i < 12; i++) {
        board[i] = 1;
        board[31 - i] = 2;
    }
    for(int i = 12; i < 20; i++){
        board[i] = 0;
    }
}

Board::Board(small * temple) {
    for(int i = 0; i < 32; i++){
        board[i] = temple[i];
    }

}

vector<small>* Board::getMoveMap(small type){
    switch(type){
        case 0:
            return whiteMoveMap;
        case 1:
            return blackMoveMap;
        default:
            return kingMoveMap;
    }
}

small Board::getColor(small piece) {
    if(piece == 1 || piece == 3){
        return 1;
    }
    else if(piece == 2 || piece == 4){
        return 0;
    }
    return -1;
}

int Board::finalJump(small start, small capt){
    int sub = start - capt;
    //Even row is 0, odd row is 1
    int t = capt % 8;
    if(t == 0 || t == 7){
        return 64;
    }
    //cout << "Start: " << (int)start << " Capture: " << (int)capt << endl;
    small even = (start / 4) % 2;
    if(sub == 3 || sub == 5){
        return capt - 4;
    }
    else if(sub == 4){
        if(even == 0){
            return capt - 3;
        }
        else{
            return capt - 5;
        }
    }
    else if (sub == -3 || sub == -5){
        return capt + 4;
    }
    else{
        if(even == 0){
            return capt + 5;
        }
        else{
            return capt + 3;
        }
    }
}
vector<pair<small, small>> Board::singleJump(small square, small * currB){
//    Board b = Board(currB);
//    cout << "Square " << (int)square << endl;
//    cout << b;
    small piece = currB[square];
    vector<small>* squareMap;
    vector<pair<small, small>> res;
    //cout << int(piece) << "  Value" << endl;
    if(piece == 0){

    }
    if(piece == 1){
        //cout << "black\n";
        squareMap = blackMoveMap;
    }
    else if(piece == 2){
        //cout << "white\n";
        squareMap = whiteMoveMap;
    }
    else {
        //cout << "king\n";
        squareMap = kingMoveMap;
    }
    vector<small> moveMap = squareMap[square];
    small color = (piece + 1) % 2;
    //cout << "Num moves " << moveMap.size() << endl;
    for(int i = 0; i < moveMap.size(); i ++){
        //cout << "Checking square " << (int)moveMap[i] << endl;
        if(getColor(currB[moveMap[i]]) == color){
            //cout << "here 5\n";
            int end  = finalJump(square, moveMap[i]);
            //cout << "Final " << end << endl;
            if(end >= 0 && end <= 32 && currB[end] == 0){
                small e = small(end);
                res.push_back(pair(moveMap[i], e));
            }
        }
    }
    return res;
}

vector<Move> Board::getJumps(small square) {
    MoveTree* root = new MoveTree(square, board);
    queue<MoveTree*> nodes;
    nodes.push(root);
    //Create tree of moves
    while(!nodes.empty()){
        MoveTree* cur = nodes.front();
        nodes.pop();
        //cout << cur;
        auto jumps = singleJump(cur->getSquare(), cur->getBoard());
        for(pair<small, small> p : jumps){
            //cout << "here " << (int)p.first << " " << (int)p.second << endl;
            bool newKing = false;
            small* b= doMove(cur->getSquare(), p.second, p.first, cur->getBoard(), newKing);
            //MoveTree tmp = MoveTree(p.second, cur->getDepth() + 1, p.first, cur, b);
            //cout << tmp;
            MoveTree* newChild = new MoveTree(p.second, cur->getDepth() + 1, p.first, cur, b);
            cur->addChild(newChild);
            //cout << cur.getNext().back();
            if(!newKing){
                nodes.push(newChild);
            }
        }
    }
    return MoveTree::jumpMoves(*root);
}

vector<Move> Board::possibleMoves(small color) {
    vector<Move> moves;
    small numJumps = 0;
    small king;
    small piece;
    vector<small>* pieceMap;
    vector<small>* kingMap;
    for(int i = 0; i < 32; i++){
        vector<Move> jumps;
        if(board[i] == 0){
            continue;
        }
        else if(color == board[i] % 2){
            //cout << i << endl;
            jumps = getJumps(i);
//            if(i == 10){
//                cout << jumps[0];
//            }
        }
        else{
            continue;
        }
        if(jumps.size() != 0){
            small curMax = maxJumps(jumps);
            if(curMax > numJumps){
                moves = jumps;
                numJumps = curMax;
            }
            else if(curMax == numJumps){
                for(Move m : jumps){
                    moves.push_back(m);
                }
            }
        }
    }
    if(!moves.empty()){
        return moves;
    }
    if(color == 0){
        king = 4;
        piece = 2;
        pieceMap = whiteMoveMap;
    }
    else{
        king = 3;
        piece = 1;
        pieceMap = blackMoveMap;
    }
    kingMap = kingMoveMap;
    for(int i = 0; i < 32; i++) {
        if (board[i] == piece) {
            for (small sq: pieceMap[i]) {
                if (board[sq] == 0) {
                    moves.emplace_back(i, sq);
                }
            }
        }
        else if (board[i] == king) {
            for (small sq: kingMap[i]) {
                if (board[sq] == 0) {
                    moves.emplace_back(i, sq);
                }
            }
        }
    }
    return moves;
}


small *Board::doMove(Move move, small* curBoard) {
    auto *cBoard = new small[32];
    copy(curBoard,curBoard + 32,cBoard);
    cBoard[move.getEnd()] = cBoard[move.getStart()];
    cBoard[move.getStart()] = 0;
    for(small square : move.getRemove()){
        cBoard[square] = 0;
    }
    king(move.getEnd(), curBoard);
    return cBoard;
}

void Board::doMove(Move move) {
    board[move.getEnd()] = board[move.getStart()];
    board[move.getStart()] = 0;
    for(small square : move.getRemove()){
        board[square] = 0;
    }
    king(move.getEnd(), board);
}

small* Board::doMove(small start, small end, small remove, small * curBoard, bool &newKing){
    small* cBoard = new small[32];
    copy(curBoard,curBoard + 32,cBoard);
    cBoard[end] = cBoard[start];
    cBoard[start] = 0;
    cBoard[remove] = 0;
    newKing = king(end, curBoard);
    return cBoard;
}

bool Board::king(small square, small* b) {
    if(square < 4){
        if(b[square] == 2){
            b[square] = 4;
            return true;
        }
    }
    else if(square > 27){
        if(b[square] == 1){
            b[square] = 3;
            return true;
        }
    }
    return false;
}

small Board::maxJumps(vector<Move> list) {
    return list[0].getRemove().size();
}

void Board::updateBoard(Move move) {
    doMove(move);
}

void Board::initializeMaps() {
    for(int i = 0; i < 32; i++){
        if(i < 28){
            kingMoveMap[i].push_back(i + 4);
            blackMoveMap[i].push_back(i + 4);
        }
        if(i > 3){
            kingMoveMap[i].push_back(i - 4);
            whiteMoveMap[i].push_back(i - 4);
        }
        //On an even row
        if((i / 4) % 2 == 0){
            //Going Forward
            if(i < 28 && i % 8 != 0){
                kingMoveMap[i].push_back(i + 3);
                blackMoveMap[i].push_back(i + 3);
            }
            //Going backward
            if(i > 3 && i % 8 != 0){
                whiteMoveMap[i].push_back(i - 5);
                kingMoveMap[i].push_back(i - 5);
            }

        }
            //On an odd row
        else{
            if(i < 28 && i % 8 != 7){
                kingMoveMap[i].push_back(i + 5);
                blackMoveMap[i].push_back(i + 5);
            }
            //Going backward
            if(i > 3 && i % 8 != 7){
                whiteMoveMap[i].push_back(i - 3);
                kingMoveMap[i].push_back(i - 3);
            }
        }
    }

}

ostream &operator<<(ostream &out, Board b) {
    int i = 28;
    while(i >= 0){
        if(i % 8 == 4){
            out << "   ";
        }
        if(b.board[i] == 0){
            out << "___";
        }
        else if(b.board[i] == 1){
            out << "_b_";
        }
        else if(b.board[i] == 2){
            out << "_w_";
        }
        else if(b.board[i] == 3){
            out << "_B_";
        }
        else if(b.board[i] == 4){
            out << "_W_";
        }
        else{
            out << "_" << b.board[i] << "_";
        }
        out << "   ";
        if(i % 4 == 3){
            out << endl;
            i -= 7;
        }
        else{
            i++;
        }
    }
    return out;
}

Board Board::randomBoard() {
    small fill[32];
    small whiteCount = 12;
    small blackCount = 12;
    for(int i = 0; i < 32; i++){
        int r = rand() % 6;
        if((r == 1 || r == 3) && blackCount > 0){
            blackCount--;
            fill[i] = r;
        }
        else if((r == 2 || r == 4) && whiteCount > 0){
            whiteCount--;
            fill[i] = r;
        }
        else{
            fill[i] = 0;
        }
    }
    return Board(fill);
}

small *Board::getBoard() {
    return board;
}


