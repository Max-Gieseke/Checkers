//
// Created by maxgi on 8/22/2023.
//

#ifndef CHECKERS_ZOBRISTHASH_H
#define CHECKERS_ZOBRISTHASH_H
#include <random>
#include "Board.h"

class ZobristHash {
private:
    unsigned long long int zTable[32][4];
    std::mt19937 mTwist;

public:
    ZobristHash();
    unsigned long long int randomInt();
    unsigned long long int calcHash(Board);

};


#endif //CHECKERS_ZOBRISTHASH_H
