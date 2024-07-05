//
// Created by maxgi on 8/20/2023.
//

#include "../include/Move.h"

#include <utility>

Move::Move() {
    start = -1;
    end = -1;
    remove = std::vector<small>();
}

Move::Move(small start, small end) {
    this->start = start;
    this->end = end;
}

void Move::addJump(small square) {
    remove.push_back(square);
}

small Move::getStart() const {
    return start;
}

small Move::getEnd() const {
    return end;
}

std::vector<small> Move::getRemove() const {
    return remove;
}

std::ostream &operator<<(std::ostream &out, const Move& m) {
    out << (int)m.start << " ==> " << (int)m.end << std::endl;
    if (!m.remove.empty()) {
        out << "Captures    ";
        for (small sq : m.remove) {
            out << (int)sq << " ";
        }
        out << std::endl;
    }
    return out;
}

Move& Move::operator=(const Move& other) {
    if (this != &other) {
        this->start = other.start;
        this->end = other.end;
        this->remove = other.remove;
    }
    return *this;
}

bool Move::equals(const Move& other) {
    if (this->start != other.start) {
        return false;
    }
    if (this->end != other.end) {
        return false;
    }
    if (this->remove.size() != other.remove.size()) {
        return false;
    }
    for (int i = 0; i < this->remove.size(); i++) {
        if (this->remove[i] != other.remove[i]) {
            return false;
        }
    }
    return true;
}

Move::Move(small s, small e, std::vector<small> remove) {
    this->start = s;
    this->end = e;
    this->remove = std::move(remove);
}

bool Move::isCapture() const {
    return !(remove.empty());
}
