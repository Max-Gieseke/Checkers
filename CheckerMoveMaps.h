//
// Created by maxgi on 10/31/2023.
//

#ifndef CHECKERS_CHECKERMOVEMAPS_H
#define CHECKERS_CHECKERMOVEMAPS_H
#include <vector>
using small = unsigned char;

class CheckerMoveMaps {
public:
    static CheckerMoveMaps& getInstance();
    const std::vector<small>* getMoveMap(small);

private:
    CheckerMoveMaps();
    std::vector<small> whiteMoveMap[32];
    std::vector<small> blackMoveMap[32];
    std::vector<small> kingMoveMap[32];

};


#endif //CHECKERS_CHECKERMOVEMAPS_H
