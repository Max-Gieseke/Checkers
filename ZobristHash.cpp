//
// Created by maxgi on 8/22/2023.
//

#include "ZobristHash.h"

unsigned long long int ZobristHash::randomInt() {
    std::uniform_int_distribution<unsigned long long int> dist(0, UINT64_MAX);
    return dist(mTwist);
}


ZobristHash::ZobristHash() : mTwist(122134){
    for(int i = 0; i < 32; i ++){
        for(int j = 0; j < 4; j++){
            zTable[i][j] = randomInt();
        }
    }

}

unsigned long long int ZobristHash::calcHash(Board b) {
    unsigned long long int cVal = 0;
    for(int i = 0; i < 32; i++){
        if(b.getBoard()[i] != 0){
            cVal ^= zTable[i][b.getBoard()[i] - 1];
        }
    }
    return cVal;
}
