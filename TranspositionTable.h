//
// Created by Max Gieseke on 8/22/2023.
//

#ifndef CHECKERS_TRANSPOSITIONTABLE_H
#define CHECKERS_TRANSPOSITIONTABLE_H
#include "ZobristHash.h"
#include <unordered_map>


class TranspositionTable {
    struct Datum {
        double evaluation;
        int depth;
        CheckerBoard board;
    };
private:
    ZobristHash hash;
    std::unordered_map<unsigned long long int, Datum> table;
public:
    TranspositionTable();
    double getValue(unsigned long long int);
    void addValue(const CheckerBoard&, int, double);
    unsigned long long int computeHash(CheckerBoard);
    bool isIn(CheckerBoard, int);
    double getEvaluation(CheckerBoard);

};


#endif //CHECKERS_TRANSPOSITIONTABLE_H
