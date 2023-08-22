//
// Created by maxgi on 12/21/2022.
//

#include "MoveTree.h"
using small = unsigned char;

MoveTree::MoveTree() {
    square = 64;
    depth = 0;
    next = vector<MoveTree*>();
    parent = nullptr;
}
MoveTree::MoveTree(small square, small* board) {
    this->square = square;
    depth = 0;
    jumped = 64;
    next = vector<MoveTree*>();
    parent = nullptr;
    copy(board, board+32, this->board);
}

MoveTree::MoveTree(small square, small depth, MoveTree* p, small* board) {
    this->square = square;
    this->depth = depth;
    parent = p;
    next = vector<MoveTree*>();
    copy(board, board+32, this->board);
}

MoveTree::MoveTree(small square, small depth, small jumped, MoveTree* p, small* board) {
    this->square = square;
    this->depth = depth;
    this->jumped = jumped;
    parent = p;
    next = vector<MoveTree*>();
    copy(board, board+32, this->board);
}

//bool MoveTree::hasSquare(small check){
//    if(check == square){
//        return true;
//    }
//    if(next == nullptr){
//        return false;
//    }
//    for(MoveTree m : *next){
//        if(m.hasSquare(check)){
//            return true;
//        }
//    }
//    return false;
//}

//vector<MoveTree>* MoveTree::getSquare(small check, small jumps){
//    if(check == square && depth == jumps){
//        return next;
//    }
//    for(MoveTree m : *next){
//        vector<MoveTree>* tmp = m.getSquare(check, jumps);
//        if(tmp != nullptr){
//            return tmp;
//        }
//    }
//}

MoveTree::small MoveTree::getSquare() {
    return square;
}

MoveTree::small MoveTree::getDepth() {
    return depth;
}

vector<MoveTree*> MoveTree::getNext() {
    return next;
}

MoveTree* MoveTree::getParent() {
    return parent;
}

void MoveTree::addChild(MoveTree* child) {
    this->next.push_back(child);
}

small MoveTree::maxDepth() {
    if(this->next.empty()){
        return depth;
    }
    small max = 0;
    for(MoveTree* n : next){
        if(n->maxDepth() > max){
            max = n->maxDepth();
        }
    }
    return max;
}

void MoveTree::getRemainingSequence(vector<small>& holder){
    if(depth == 0){
        holder.push_back(square);
    }
    else{
        holder.push_back(jumped);
        this->parent->getRemainingSequence(holder);
    }
}

void MoveTree::maxSequences(small depth, vector<vector<small>>& holder) {
    if(this->depth == depth){
        holder.push_back(vector<small>());
        holder.back().push_back(this->square);
        getRemainingSequence(holder.back());
        cout << endl;
    }
    else{
        for(MoveTree* node : this->next){
            node->maxSequences(depth, holder);
        }
    }

}



vector<Move> MoveTree::jumpMoves(MoveTree head) {
    small longest = head.maxDepth();
    if(longest == 0){
        return vector<Move>();
    }
    vector<vector<small>> invertedJumps;
    head.maxSequences(longest, invertedJumps);
    vector<Move> holder;
    //seq[0] is last position, seq.back() is first square, all others are jumps
    for(vector<small> seq : invertedJumps){
        Move tmp = Move(seq.back(), seq.front());
        for(int i = 1; i < seq.size() - 1; i++){
            tmp.addJump(seq[i]);
        }
        holder.push_back(tmp);
    }

    return holder;
}

small *MoveTree::getBoard() {
    return this->board;
}

ostream &operator<<(ostream &out, MoveTree m) {
    out << "Current: " << (int)m.square << " Captured " << (int)m.jumped << endl;
    if(m.parent == nullptr){
        out << "Parent Square " << "none\n";
    }
    else{
        out << "Parent Square " << (int) m.parent->square << endl;

    }
    return out;
}



