//
// Created by maxgi on 10/31/2023.
//

#include "CheckerLogic.h"

std::vector<std::pair<small, small>> CheckerLogic::singleJump(small square, const CheckerBoard& checkerboard) {
    small piece = checkerboard.getPiece(square);
    const std::vector<std::vector<small>>& squareMap = CheckerMoveMaps::getInstance().getMoveMap(piece);
    std::vector<std::pair<small, small>> result;
    const std::vector<small> moveMap = squareMap[square];
    small color = (piece + 1) % 2;
    for(const unsigned char& sq : moveMap){
        if(getColor(checkerboard.getPiece(sq)) == color){
            int end = finalJump(square, sq);
            if(end >= 0 && end < 32 && checkerboard.getPiece(end) == 0){
                small e = small(end);
                result.emplace_back(sq, e);
            }
        }
    }
    return result;
}

std::vector<Move> CheckerLogic::getJumps(small square, const CheckerBoard& board) {
    JumpTree head = JumpTree(square, board);
    std::queue<std::shared_ptr<JumpNode>> nodes;
    nodes.push(head.getRoot());
    while(!nodes.empty()){
        std::shared_ptr<JumpNode> cur = nodes.front();
        nodes.pop();
        std::vector<std::pair<small, small>> jumps = singleJump(cur->getSquare(), cur->getBoard());
        for(std::pair<small, small> p : jumps){
            //cout << "here " << (int)p.first << " " << (int)p.second << endl;
            bool newKing = false;
            CheckerBoard b = doSingleJump(cur->getSquare(), p.second, p.first, cur->getBoard(), newKing);
            //JumpTree tmp = JumpTree(p.second, cur->getDepth() + 1, p.first, cur, b);
            //cout << tmp;
            std::shared_ptr<JumpNode> newChild = std::make_shared<JumpNode>(p.second, cur->getDepth() + 1, p.first, cur, b);
            if(newChild->getSquare() == 32){
                std::cout << "Square: " << static_cast<int>(newChild->getSquare()) << std::endl;
                std::cout << newChild->getBoard();
                std::cout << "Parent board and square: " << static_cast<int>(cur->getSquare())  << " ::"<< std::endl;
                std::cout << cur->getBoard();
            }
            cur->addChild(newChild);
            //cout << cur.getNext().back();
            if(!newKing){
                nodes.push(newChild);
            }
        }
    }
    std::vector<Move> moves = head.jumpMoves();
    head.clearTree();
    return moves;
}

std::vector<Move> CheckerLogic::possibleMoves(const CheckerBoard& board) {
    //currentPlayer is 0 for white, 1 for black
    small currentPlayer = board.getPlayer();
    std::vector<Move> moves;
    small numJumps = 0;
    small king;
    small piece;
    for(int i = 0; i < 32; i++){
        std::vector<Move> jumps;
        small curPiece = board.getPiece(i);
        if(curPiece != 0 && currentPlayer == curPiece % 2){
            //cout << i << endl;
            // if(i == 32){
            //     std::cout << "I: " << static_cast<int>(square) << std::endl;
            //     std::cout << board;
            // }
            jumps = getJumps(i, board);
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
    if(currentPlayer == 0){
        king = 4;
        piece = 2;
    }
    else{
        king = 3;
        piece = 1;
    }
    const std::vector<std::vector<small>>& pieceMap = CheckerMoveMaps::getInstance().getMoveMap(piece);
    const std::vector<std::vector<small>>& kingMap = CheckerMoveMaps::getInstance().getMoveMap(3);
    for(int i = 0; i < 32; i++) {
        small curPiece = board.getPiece(i);
        if (curPiece == piece) {
            for (small sq: pieceMap[i]) {
                if (board.getPiece(sq) == 0) {
                    moves.emplace_back(i, sq);
                }
            }
        }
        else if (curPiece == king) {
            for (small sq: kingMap[i]) {
                if (board.getPiece(sq) == 0) {
                    moves.emplace_back(i, sq);
                }
            }
        }
    }
    return moves;
}

CheckerBoard CheckerLogic::doMove(const Move& move, const CheckerBoard& board) {
    CheckerBoard nBoard = board;
    nBoard.movePiece(move.getStart(), move.getEnd());
    for(const small& sq : move.getRemove()){
        nBoard.removePiece(sq);
    }
    return nBoard;
}

CheckerBoard CheckerLogic::doTurn(const Move& move, const CheckerBoard& board) {
    CheckerBoard nBoard = board;
    nBoard.movePiece(move.getStart(), move.getEnd());
    for(const small& sq : move.getRemove()){
        nBoard.removePiece(sq);
    }
    nBoard.switchPlayer();
    return nBoard;
}


small CheckerLogic::getColor(small piece) {
    if(piece == 1 || piece == 3){
        return 1;
    }
    else if(piece == 2 || piece == 4){
        return 0;
    }
    return -1;
}

int CheckerLogic::finalJump(small start, small capt) {
    int sub = start - capt;
    //Even row is 0, odd row is 1
    int t = capt % 8;
    // if(start == 25 && capt == 28){
    //     std::cout << "In finalJump, t = " << t << std::endl;
    // }
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

CheckerBoard CheckerLogic::doSingleJump(small start, small end, small remove, const CheckerBoard &curBoard, bool &newKing) {
    CheckerBoard cBoard = curBoard;
    newKing = cBoard.movePiece(start, end);
    cBoard.removePiece(remove);
    return cBoard;
}

small CheckerLogic::maxJumps(std::vector<Move> list) {
    return list[0].getRemove().size();
}

double CheckerLogic::scoreBoard(const CheckerBoard & board) {
    double curBlack = 0;
    double curWhite = 0;
    Scores points = Scores::getInstance();
//    std::cout << " at 0 "<< static_cast<int>(board.getPiece(0)) << std::endl;
//    std::cout << " at 31 "<< static_cast<int>(board.getPiece(31)) << std::endl;
    for(int i = 0; i < 32; i ++){
        //black pawn
        small curPiece = board.getPiece(i);
        //std:: cout <<i << " " << static_cast<int>(curPiece) << std::endl;
        if(curPiece == 1){
            curBlack += points.pawnVal;
            curBlack += points.rankBonus * (i / 4);
        }
            //white pawn
        else if(curPiece == 2){
            curWhite += points.pawnVal;
            curWhite += points.rankBonus * (7 - (i / 4));
        }
            //black king
        else if(curPiece == 3){
            curBlack += points.kingVal;
        }
            //white king
        else if(curPiece == 4){
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


std::pair<double, Move> CheckerLogic::exploreMoves(int left, CheckerBoard board) {
    if(left <= 0){
        return {CheckerLogic::scoreBoard(board), Move()};
    }
    std::vector<Move> moves = CheckerLogic::possibleMoves(board);
    int multiply = 1;
    if(board.getPlayer() == 0){
        multiply = -1;
    }
    Move best;
    double max = -INT32_MAX;
    for(const auto& m : moves){
        std::pair<double, Move> tmp;
        CheckerBoard tmpBoard = CheckerLogic::doTurn(m, board);
        tmp = exploreMoves(left - 1, tmpBoard);
        if(multiply * tmp.first > max){
            max = multiply * tmp.first;
            best = m;
        }
    }
    return {max, best};
}
