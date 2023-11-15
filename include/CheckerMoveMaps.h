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
    const std::vector<std::vector<small>>& getMoveMap(small);

private:
    CheckerMoveMaps();
    std::vector<std::vector<small>> whiteMoveMap;
    std::vector<std::vector<small>> blackMoveMap;
    std::vector<std::vector<small>> kingMoveMap;

};


#endif //CHECKERS_CHECKERMOVEMAPS_H
