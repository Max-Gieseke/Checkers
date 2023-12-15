//
// Created by maxgi on 12/7/2023.
//
#include "../include/MCPlayer.h"
#include "../include/AiPlayer.h"
#include "../include/RandomPlayer.h"



json playRound(Player* p1, Player* p2);
void recordResults(const json& toWrite);


int main() {
    Player* mcPlayer = new MCPlayer(4, 3.93);
    Player* mmPlayer = new AiPlayer(11, Scores(Scores::loadBestScores()));
    Player* randPlayer = new RandomPlayer();
    json data;

    //random vs mmPlayer
    std::cout << "Random vs mm\n";
    json tmp = playRound(randPlayer, mmPlayer);
    json tmp2;
    tmp2["Random"] = tmp["p1Wins"];
    tmp2["MiniMax"] = tmp["p2Wins"];
    tmp2["Draws"] = tmp["Draws"];
    data["randVsMinimax"] = tmp2;

    //mcPlayer vs mmPlayer
    std::cout << "MC vs mm\n";
    tmp = playRound(mcPlayer, mmPlayer);
    std::cout << std::setw(4) << tmp;
    json tmp3;
    tmp3["MonteCarlo"] = tmp["p1Wins"];
    tmp3["MiniMax"] = tmp["p2Wins"];
    tmp3["Draws"] = tmp["Draws"];
    data["MonteCarloVsMinimax"] = tmp3;
    std::cout << std::setw(4) << tmp;

    //mcPlayer vs random
    std::cout << "MC vs Random\n";
    tmp = playRound(mcPlayer, randPlayer);
    json tmp4;
    tmp4["MonteCarlo"] = tmp["p1Wins"];
    tmp4["Random"] = tmp["p2Wins"];
    tmp4["Draws"] = tmp["Draws"];
    data["MonteCarloVsRandom"] = tmp4;

    recordResults(data);
}

void recordResults(const json& toWrite){
    std::string path = "../Tournament_Results/";
    std::filesystem::create_directory(path);
    path = path + "/results.json";
    std::ofstream oFile(path);
    if(oFile.is_open()){
        oFile << std::setw(4) << toWrite;
    }
    else {
        std::cerr << "Error opening file\n";
    }
}

json playRound(Player* p1, Player* p2) {
    int p1Wins = 0;
    int p1Losses = 0;
    int draws = 0;
    json tmp;
    for(int i = 0; i < 10; i++) {
        int res = Player::playGame(*p1, *p2);
        if (res > 0) {
            std::cout << "Player 1 won\n";
            p1Wins++;
        }
        else if (res < 0) {
            std::cout << "Player 2 won\n";
            p1Losses++;
        }
        else {
            std::cout << "Draw\n";
            draws++;
        }
        res = Player::playGame(*p2, *p1);
        if (res > 0) {
            std::cout << "Player 2 won\n";
            p1Losses++;
        }
        else if (res < 0) {
            std::cout << "Player 1 won\n";
            p1Wins++;
        }
        else {
            draws++;
        }
    }
    tmp["p1Wins"] = p1Wins;
    tmp["p2Wins"] = p1Losses;
    tmp["Draws"] = draws;
    return tmp;
}

