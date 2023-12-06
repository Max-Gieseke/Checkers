//
// Created by maxgi on 8/22/2023.
//

#include "../include/Scores.h"
#include <iostream>
//Temporary testing scores
Scores::Scores() {
    pawnVal = 2;
    kingVal = 4;
    rankBonus = 0.12;
    win = INT32_MAX;
}


Scores::Scores(const json& data) {
    pawnVal = data["pawnVal"];
    kingVal = data["KingVal"];
    win = data["win"];
    rankBonus = data["rankBonus"];
}

json Scores::scoresToJson() {
    json data;
    data["pawnVal"] = pawnVal;
    data["KingVal"] = kingVal;
    data["win"] = win;
    data["rankBonus"] = rankBonus;
    return data;
}
