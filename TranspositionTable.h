//
// Created by Max Gieseke on 8/22/2023.
//

#ifndef CHECKERS_TRANSPOSITIONTABLE_H
#define CHECKERS_TRANSPOSITIONTABLE_H
#include "ZobristHash.h"
#include <unordered_map>
#include "MoveNode.h"


class TranspositionTable {
private:
    ZobristHash hash;
    std::unordered_map<unsigned long long int, MoveNode*> table;
public:
    TranspositionTable();
    MoveNode* getValue(unsigned long long int);
    void addValue(MoveNode*);
    unsigned long long int computeHash(Board);
    bool isIn(Board, int);
    MoveNode* getNode(Board);

};


#endif //CHECKERS_TRANSPOSITIONTABLE_H
