//
// Created by maxgi on 8/22/2023.
//

#include "TranspositionTable.h"

TranspositionTable::TranspositionTable() {
    hash = ZobristHash();
}

void TranspositionTable::addValue(std::shared_ptr<MoveNode> node) {
    unsigned long long int key = hash.calcHash(node->getBoard());
    table[key] = node;
}

std::shared_ptr<MoveNode> TranspositionTable::getValue(unsigned long long int key) {
    return table[key];
}

unsigned long long int TranspositionTable::computeHash(CheckerBoard b) {
    return hash.calcHash(b);
}

bool TranspositionTable::isIn(CheckerBoard b, int depth) {
    unsigned long long int key = hash.calcHash(b);
    if(table.count(key) == 0){
        return false;
    }
    if(table[key]->getDepth() < depth){
        return false;
    }
    return true;
}

std::shared_ptr<MoveNode> TranspositionTable::getNode(CheckerBoard b) {
    return table[hash.calcHash(b)];
}

