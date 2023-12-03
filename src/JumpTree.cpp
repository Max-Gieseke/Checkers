//
// Created by maxgi on 12/21/2022.
//

#include "../include/JumpTree.h"

JumpTree::JumpTree(small square, CheckerBoard board) {
    root = std::make_shared<JumpNode>(square, board);
}

std::shared_ptr<JumpNode> JumpTree::getRoot() {
    return root;
}



std::vector<Move> JumpTree::jumpMoves() {
    small longest = root->maxDepth();
    if(longest == 0){
        return {};
    }
    std::vector<std::vector<small>> invertedJumps;
    root->maxSequences(longest, invertedJumps);
    std::vector<Move> holder;
    //seq[0] is last position, seq.back() is first square, all others are jumps
    for(std::vector<small> seq : invertedJumps){
        Move tmp = Move(seq.back(), seq.front());
        for(int i = 1; i < seq.size() - 1; i++){
            tmp.addJump(seq[i]);
        }
        holder.push_back(tmp);
    }

    return holder;
}


void JumpTree::clearTree(){
    root->clear();
    root.reset();
}

std::vector<std::pair<small, small>> JumpTree::singleJump(small square, const CheckerBoard& board) {
    small piece = board.getPiece(square);
    const std::vector<std::vector<small>>& squareMap = CheckerMoveMaps::getInstance().getMoveMap(piece);
    std::vector<std::pair<small, small>> result;
    const std::vector<small> moveMap = squareMap[square];
    small color = (piece + 1) % 2;
    for(const unsigned char& sq : moveMap){
        if(CheckerBoard::getColor(board.getPiece(sq)) == color){
            int end = CheckerBoard::finalJump(square, sq);
            if(end >= 0 && end < 32 && board.getPiece(end) == 0){
                auto e = small(end);
                result.emplace_back(sq, e);
            }
        }
    }
    return result;
}

std::vector<Move> JumpTree::getJumps(small square, const CheckerBoard& board) {
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
            CheckerBoard b = cur->getBoard().doSingleJump(cur->getSquare(), p.second, p.first, newKing);
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

small JumpTree::maxJumps(std::vector<Move> list) {
    return list[0].getRemove().size();
}

std::vector<Move> JumpTree::possibleMoves(const CheckerBoard& board) {
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
            jumps = JumpTree::getJumps(i, board);
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


