//
// Created by maxgi on 10/31/2023.
//

#include "../include/CheckerMoveMaps.h"

CheckerMoveMaps &CheckerMoveMaps::getInstance() {
    static CheckerMoveMaps instance;
    return instance;
}

CheckerMoveMaps::CheckerMoveMaps() {
    whiteMoveMap.resize(32, std::vector<small>());
    blackMoveMap.resize(32, std::vector<small>());
    kingMoveMap.resize(32, std::vector<small>());
    for (int i = 0; i < 32; i++) {
        if (i < 28) {
            kingMoveMap[i].push_back(i + 4);
            blackMoveMap[i].push_back(i + 4);
        }
        if (i > 3) {
            kingMoveMap[i].push_back(i - 4);
            whiteMoveMap[i].push_back(i - 4);
        }
        //On an even row
        if ((i / 4) % 2 == 0) {
            //Going Forward
            if (i < 28 && i % 8 != 0) {
                kingMoveMap[i].push_back(i + 3);
                blackMoveMap[i].push_back(i + 3);
            }
            //Going backward
            if (i > 3 && i % 8 != 0) {
                whiteMoveMap[i].push_back(i - 5);
                kingMoveMap[i].push_back(i - 5);
            }

        }
            //On an odd row
        else {
            if (i < 28 && i % 8 != 7) {
                kingMoveMap[i].push_back(i + 5);
                blackMoveMap[i].push_back(i + 5);
            }
            //Going backward
            if (i > 3 && i % 8 != 7) {
                whiteMoveMap[i].push_back(i - 3);
                kingMoveMap[i].push_back(i - 3);
            }
        }
    }

}

const std::vector<std::vector<small>>& CheckerMoveMaps::getMoveMap(small piece) {
    switch(piece) {
        case 1:
            return blackMoveMap;
        case 2:
            return whiteMoveMap;
        default:
            return kingMoveMap;
    }
}
