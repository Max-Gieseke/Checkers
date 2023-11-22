//
// Created by maxgi on 8/23/2023.
//

#include "cstdlib"
#include "../include/AiPlayer.h"
#include "../include/HumanPlayer.h"

json loadFromLatestGen();
int DEPTH = 12;

int main(){
    HumanPlayer human;
    json vals = loadFromLatestGen();
    AiPlayer ai = AiPlayer(12);
    CheckerBoard board;
    double eval = 0;
    std::cout << board;
    std::pair<double, Move> temp;
    int tmp;
    while(eval < 99 && eval > -99){
        human.completeTurn(board);
        std::cout << board;
        if(board.gameOver()){
            std::cout << "You win!\n";
            break;
        }
        ai.completeTurn(board);
        std::cout << "------------------------------------\n";
        std::cout << "Evaluation: " << board.scoreBoard(ai.getScoring()) << std::endl;
        std::cout << board;
        if(board.gameOver()){
            std::cout << "You lost\n";
            break;
        }
    }
}


json loadFromLatestGen(){
    std::string pathToGenerations = "../Generation_Results/";
    int curGen = 0;
    for(const auto& entry : std::filesystem::directory_iterator(pathToGenerations)){
        std::string fileName = entry.path().filename().string();
        int num = std::stoi(fileName.substr(fileName.find('_') + 1));
        if(num > curGen){
            curGen = num;
        }
    }

    std::string pathToFile = "../Generation_Results/Generation_" + std::to_string(curGen) + "/results.json";
    std::ifstream inFile(pathToFile);
    json lastGen;

    if(inFile.is_open()){
        inFile >> lastGen;
    }
    else {
        std::cerr << "Error opening file " << pathToFile << std::endl;
    }
    double bestScore = 0;
    json bestParams;
    for(json& player : lastGen) {
        if(player["Result"] > bestScore){
            bestScore = player["Result"];
            bestParams = player["Parameters"];
        }
    }
    return bestParams;
}