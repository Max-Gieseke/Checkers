//
// Created by Max Gieseke on 8/22/2023.
//

#ifndef CHECKERS_TRANSPOSITIONTABLE_H
#define CHECKERS_TRANSPOSITIONTABLE_H
#include "ZobristHash.h"
#include <unordered_map>
#include <shared_mutex>


class TranspositionTable {
    struct Datum {
        float evaluation;
        int depth;
        CheckerBoard board;
    };
private:
    mutable std::shared_mutex mutex;
    ZobristHash hash;
    std::unordered_map<unsigned long long int, Datum> table;
public:
    TranspositionTable();
    TranspositionTable(const TranspositionTable&);
    double getValue(unsigned long long int);
    void addValue(const CheckerBoard&, int, float);
    unsigned long long int computeHash(CheckerBoard);
    bool isIn(CheckerBoard, int);
    float getEvaluation(CheckerBoard);
    TranspositionTable& operator=(const TranspositionTable& other);

};


#endif //CHECKERS_TRANSPOSITIONTABLE_H
