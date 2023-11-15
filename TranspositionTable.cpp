//
// Created by maxgi on 8/22/2023.
//

#include "TranspositionTable.h"

TranspositionTable::TranspositionTable() {
    hash = ZobristHash();
}

void TranspositionTable::addValue(const CheckerBoard& board, int depth, double eval) {
    unsigned long long int key = hash.calcHash(board);
    Datum tmp = {eval, depth, board};
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

double TranspositionTable::getEvaluation(CheckerBoard b) {
    return table[hash.calcHash(b)].evaluation;
}


