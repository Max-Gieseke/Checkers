//
// Created by Max Gieseke on 12/21/2022.
// Add class-wide variables for num pieces and squares

#include "Board.h"

std::vector<small> whiteMoveMap[32];
std::vector<small> blackMoveMap[32];
std::vector<small> kingMoveMap[32];
Scores points;

Board::Board(){
    // Initialize squares to starting values
    for(int i = 0; i < 12; i++) {
        board[i] = 1;
        board[31 - i] = 2;
    }
    for(int i = 12; i < 20; i++){
        board[i] = 0;
    }
    currentPlayer = 1;
}

Board::Board(const small* temple, small turn) {
    for(int i = 0; i < 32; i++){
        board[i] = temple[i];
    }
    currentPlayer = turn;

}

std::vector<small>* Board::getMoveMap(small type){
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
std::vector<std::pair<small, small>> Board::singleJump(small square, small * currB){
//    Board b = Board(currB);
//    cout << "Square " << (int)square << endl;
//    cout << b;
    small piece = currB[square];
    std::vector<small>* squareMap;
    std::vector<std::pair<small, small>> res;
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
    std::vector<small> moveMap = squareMap[square];
    small color = (piece + 1) % 2;
    //cout << "Num moves " << moveMap.size() << endl;
    for(unsigned char & sq : moveMap){
        //cout << "Checking square " << (int)moveMap[i] << endl;
        if(getColor(currB[sq]) == color){
            //cout << "here 5\n";
            int end  = finalJump(square, sq);
            //cout << "Final " << end << endl;
            if(end >= 0 && end <= 32 && currB[end] == 0){
                small e = small(end);
                res.emplace_back(sq, e);
            }
        }
    }
    return res;
}

std::vector<Move> Board::getJumps(small square) {
    JumpTree root = JumpTree(square, board);
    std::queue<JumpTree*> nodes;
    nodes.push(&root);
    //Create tree of moves
    while(!nodes.empty()){
        JumpTree* cur = nodes.front();
        nodes.pop();
        //cout << cur;
        auto jumps = singleJump(cur->getSquare(), cur->getBoard());
        for(std::pair<small, small> p : jumps){
            //cout << "here " << (int)p.first << " " << (int)p.second << endl;
            bool newKing = false;
            small* b= doMove(cur->getSquare(), p.second, p.first, cur->getBoard(), newKing);
            //JumpTree tmp = JumpTree(p.second, cur->getDepth() + 1, p.first, cur, b);
            //cout << tmp;
            JumpTree* newChild = new JumpTree(p.second, cur->getDepth() + 1, p.first, cur, b);
            cur->addChild(newChild);
            //cout << cur.getNext().back();
            if(!newKing){
                nodes.push(newChild);
            }
        }
    }
    return JumpTree::jumpMoves(root);
}

std::vector<Move> Board::possibleMoves() {
    std::vector<Move> moves;
    small numJumps = 0;
    small king;
    small piece;
    std::vector<small>* pieceMap;
    std::vector<small>* kingMap;
    for(int i = 0; i < 32; i++){
        std::vector<Move> jumps;
        if(board[i] != 0 && this->currentPlayer == board[i] % 2){
            //cout << i << endl;
            jumps = getJumps(i);
        }
        else{
            continue;
        }
        if(!jumps.empty()){
            small curMax = maxJumps(jumps);
            if(curMax > numJumps){
                moves = jumps;
                numJumps = curMax;
            }
            else if(curMax == numJumps){
                for(const Move& m : jumps){
                    moves.push_back(m);
                }
            }
        }
    }
    if(!moves.empty()){
        return moves;
    }
    if(this->currentPlayer == 0){
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


Board Board::doMove(Move move, Board b) {
    auto *cBoard = new small[32];
    std::copy(b.board,b.board + 32,cBoard);
    cBoard[move.getEnd()] = cBoard[move.getStart()];
    cBoard[move.getStart()] = 0;
    for(small square : move.getRemove()){
        cBoard[square] = 0;
    }
    king(move.getEnd(), cBoard);
    return Board(cBoard, 1 - b.currentPlayer);
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
    std::copy(curBoard,curBoard + 32,cBoard);
    cBoard[end] = cBoard[start];
    cBoard[start] = 0;
    cBoard[remove] = 0;
    newKing = king(end, cBoard);
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

small Board::maxJumps(std::vector<Move> list) {
    return list[0].getRemove().size();
}

void Board::updateBoard(const Move& move) {
    doMove(move);
}

void Board::initializeMaps() {
    points = Scores();
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

std::ostream &operator<<(std::ostream &out, Board b) {
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
            out << std::endl;
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
    small whiteCount = 4;
    small blackCount = 4;
    for(unsigned char & sq : fill){
        int r = rand() % 6;
        if((r == 1 || r == 3) && blackCount > 0){
            blackCount--;
            sq = r;
        }
        else if((r == 2 || r == 4) && whiteCount > 0){
            whiteCount--;
            sq = r;
        }
        else{
            sq = 0;
        }
    }
    return Board(fill, 1);
}

small *Board::getBoard() {
    return board;
}

void Board::switchPlayer() {
    currentPlayer = 1 - currentPlayer;
}

small Board::getPlayer() const {
    return currentPlayer;
}
/**
 * Currently uses two vars to track black and white, but can use one in future
 * @return a double representing the evaluation of the position
 */
double Board::scoreBoard() {
    //double curScore;
    double curBlack = 0;
    double curWhite = 0;
    for(int i = 0; i < 32; i ++){
        //black pawn
        if(board[i] == 1){
            curBlack += points.pawnVal;
            curBlack += points.rankBonus * (i / 4.0);
        }
        //white pawn
        else if(board[i] == 2){
            curWhite += points.pawnVal;
            curWhite += points.rankBonus * (7 - (i / 4.0));
        }
        //black king
        else if(board[i] == 3){
            curBlack += points.kingVal;
        }
        //white king
        else if(board[i] == 4){
            curWhite += points.kingVal;
        }
    }
    if(curBlack == 0){
        return -100.0;
    }
    if(curWhite == 0){
        return 100.0;
    }
    return curBlack - curWhite;
}

bool Board::equals(const Board& other) {
    if(this->currentPlayer != other.currentPlayer){
        return false;
    }
    for(int i = 0; i < 32; i++){
        if(this->board[i] != other.board[i]){
            return false;
        }
    }
    return true;
}

Board &Board::operator=(const Board & other) {
    if(this != &other){
        this->currentPlayer = other.currentPlayer;
        for(int i = 0; i < 32; i++){
            this->board[i] = other.board[i];
        }
    }
    return *this;
}


