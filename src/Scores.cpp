//
// Created by maxgi on 8/22/2023.
//

#include "../include/Scores.h"
#include <iostream>
//Temporary testing scores
Scores::Scores() {
    pawnVal = 2;
    kingVal = 4;
    rankBonus = 0;
    win = INT32_MAX;
}


Scores::Scores(const json& data) {
    pawnVal = data["pawnVal"];
    kingVal = data["kingVal"];
    win = data["win"];
    rankBonus = data["rankBonus"];
}

json Scores::scoresToJson() {
    json data;
    data["pawnVal"] = pawnVal;
    data["kingVal"] = kingVal;
    data["win"] = win;
    data["rankBonus"] = rankBonus;
    return data;
}

std::ostream &operator<<(std::ostream& out, Scores scores) {
    out << "Pawn: " << scores.pawnVal << std::endl;
    out << "King: " << scores.kingVal << std::endl;
    out << "Bonus: " << scores.rankBonus << std::endl;
    out << "Win: " << scores.win << std::endl;
    return out;
}

json Scores::loadBestScores() {
    std::string pathToGenerations = "../Generation_Results/";
    int curGen = 0;
    for (const auto& entry : std::filesystem::directory_iterator(pathToGenerations)) {
        std::string fileName = entry.path().filename().string();
        int num = std::stoi(fileName.substr(fileName.find('_') + 1));
        if (num > curGen) {
            curGen = num;
        }
    }
    if (curGen == 0) {
        std::cout << "No Generations exist\n";
        return {};
    }
    std::string pathToFile = "../Generation_Results/Generation_" + std::to_string(curGen) + "/results.json";
    std::ifstream inFile(pathToFile);
    json lastGen;

    if (inFile.is_open()) {
        inFile >> lastGen;
    }
    else {
        std::cerr << "Error opening file " << pathToFile << std::endl;
    }
    double maxWins = 0;
    json bestParams;
    for (json& player : lastGen) {
        if (player["Result"] > maxWins) {
            bestParams = player["Parameters"];
            maxWins = player["Result"];
        }
    }
//    std::cout << "Loading parameters with " << maxWins << " wins\n";

    return bestParams;
}
