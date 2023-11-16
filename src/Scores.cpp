//
// Created by maxgi on 8/22/2023.
//

#include "../include/Scores.h"
//Temporary testing scores
Scores::Scores() {
    blackPawnVal = 1;
    whitePawnVal = 1;
    blackKingVal = 2;
    whiteKingVal = 2;
    pieceDifference = 1;
    winVal = 100;
    blackPawnPerSquare = std::vector<float>(32);
    whitePawnPerSquare = std::vector<float>(32);
    blackKingPerSquare = std::vector<float>(32);
    whiteKingPerSquare = std::vector<float>(32);
}


Scores::Scores(const json& data) {
    blackPawnVal = data["blackPawnVal"].template get<float>();
    whitePawnVal = data["whitePawnVal"].template get<float>();
    blackKingVal = data["blackKingVal"].template get<float>();
    whiteKingVal = data["whiteKingVal"].template get<float>();
    pieceDifference = data["pieceDifference"].template get<float>();
    winVal = data["winVal"].template get<float>();
    blackPawnPerSquare = data["blackPawnPerSquare"].template get<std::vector<float>>();
    whitePawnPerSquare = data["whitePawnPerSquare"].template get<std::vector<float>>();
    blackKingPerSquare = data["blackKingPerSquare"].template get<std::vector<float>>();
    whiteKingPerSquare = data["whiteKingPerSquare"].template get<std::vector<float>>();

}
