//
// Created by maxgi on 8/22/2023.
//

#include "TranspositionTable.h"

TranspositionTable::TranspositionTable() {
    hash = ZobristHash();
}

void TranspositionTable::addValue(long long int key, Move next, double score, int depth) {
    info_t tmp = {next, score, depth};
    table[key] = tmp;
}

TranspositionTable::info_t TranspositionTable::getValue(long long int key) {
    return table[key];
}

