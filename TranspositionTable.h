//
// Created by maxgi on 8/22/2023.
//

#ifndef CHECKERS_TRANSPOSITIONTABLE_H
#define CHECKERS_TRANSPOSITIONTABLE_H
#include "ZobristHash.h"
#include <unordered_map>
#include "Move.h"


class TranspositionTable {
private:
    struct info_t {
        Move nextMove;
        double score;
        int depthSearched;
    };
    ZobristHash hash;
    std::unordered_map<long long int, info_t> table;
public:
    TranspositionTable();
    info_t getValue(long long int);
    void addValue(long long int, Move, double, int);

};


#endif //CHECKERS_TRANSPOSITIONTABLE_H
