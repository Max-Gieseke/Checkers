//
// Created by maxgi on 8/22/2023.
//

#ifndef CHECKERS_SCORES_H
#define CHECKERS_SCORES_H
#include <fstream>
#include "../json.hpp"

using json = nlohmann::json;

class Scores {
private:

public:
    Scores();
    explicit Scores(const json&);
    json scoresToJson();
//    static Scores& getInstance();
//    double kingVal;
//    double pawnVal;
//    double noPieces;
//    double rankBonus;
    float blackPawnVal;
    float whitePawnVal;
    float blackKingVal;
    float whiteKingVal;

    float pieceDifference;
    float winVal;

    std::vector<float> blackPawnPerSquare;
    std::vector<float> whitePawnPerSquare;
    std::vector<float> blackKingPerSquare;
    std::vector<float> whiteKingPerSquare;


};


#endif //CHECKERS_SCORES_H
