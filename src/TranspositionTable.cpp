//
// Created by maxgi on 8/22/2023.
//

#include "../include/TranspositionTable.h"

TranspositionTable::TranspositionTable() {
    hash = ZobristHash();
}

void TranspositionTable::addValue(const CheckerBoard& board, int depth, float eval) {
    unsigned long long int key = hash.calcHash(board);
    Datum tmp = {eval, depth, board};
    std::lock_guard<std::shared_mutex> lock(mutex);
    table[key] = tmp;
}

double TranspositionTable::getValue(unsigned long long int key) {
    return table[key].evaluation;
}

unsigned long long int TranspositionTable::computeHash(CheckerBoard b) {
    return hash.calcHash(b);
}

bool TranspositionTable::isIn(CheckerBoard b, int depth) {
    unsigned long long int key = hash.calcHash(b);
    if(table.count(key) == 0){
        return false;
    }
    if(table[key].depth < depth){
        return false;
    }
    return true;
}

float TranspositionTable::getEvaluation(CheckerBoard b) {
    return table[hash.calcHash(b)].evaluation;
}


TranspositionTable& TranspositionTable::operator=(const TranspositionTable& other) {
    if(this != &other){
        this->table = other.table;
        this->hash = other.hash;
    }
    return *this;
}

TranspositionTable::TranspositionTable(const TranspositionTable& other) {
    this->table = other.table;
    this->hash = other.hash;
}


