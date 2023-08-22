//
// Created by maxgi on 8/20/2023.
//

#include "Move.h"

Move::Move() {
    start = 64;
    end = 64;
    remove = vector<small>();
}

Move::Move(small start, small end) {
    this->start = start;
    this->end = end;
}

void Move::addJump(small square) {
    remove.push_back(square);
}

small Move::getStart() {
    return start;
}

small Move::getEnd() {
    return end;
}

vector<small> Move::getRemove() {
    return remove;
}

ostream &operator<<(ostream &out, Move m) {
    out << (int)m.start << " ==> " << (int)m.end << endl;
    if(m.remove.size() != 0){
        out << "Captures    ";
        for(small sq : m.remove){
            out << (int)sq << " ";
        }
        out << endl;
    }
    return out;
}
