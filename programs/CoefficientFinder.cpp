//
// Created by maxgi on 12/7/2023.
//

#include "../include/MCPlayer.h"
void recordResults(const json& toWrite);

int main() {
    MCPlayer* p1 = new MCPlayer(2, 3.89);
    MCPlayer* p2 = new MCPlayer(2, 3.9351);
    double value1 = 3.89;
    double value2 = 3.9351;
    double old = 0;
    bool equalOnce = false;
    bool finished = false;
    bool p1won = false;
    while (!finished) {
        int res = Player::playGame(*p1, *p2);
        res -= Player::playGame(*p2, *p1);
        if (res > 0) {
            p1won = true;
            old = value2;
            std::cout << value1 << " beat " << value2 << std::endl;
            value2 = value2 - (1 - value1 / value2);
            if (value2 <= value1 - 0.01) {
                if(equalOnce) {
                    finished = true;
                }
                equalOnce = true;
            }
            else {
                equalOnce = false;
            }
        }
        else if (res < 0) {
            p1won = false;
            old = value1;
            std::cout << value2 << " beat " << value1 << std::endl;
            value1 = value1 + 1 - value1 / value2;
            if (value2 <= value1 - 0.01) {
                if(equalOnce) {
                    finished = true;
                }
                equalOnce = true;
            }
            else {
                equalOnce = false;
            }
        }
        else {
            std::cout << "draw\n";
            if (equalOnce) {
                finished = true;
            }
             equalOnce = true;
        }
        p1 = new MCPlayer(2, value1);
        p2 = new MCPlayer(2, value2);
    }
    json tmp;
    if(p1won) {
        std::cout << value1 << " best value\n";
        tmp["best"] = value1;
    }
    else {
        std::cout << value2 << " best value\n";
        tmp["best"] = value2;
    }
    std::cout << "final values were " << value2 << " and " << value1 << std::endl;
    recordResults(tmp);
}


//int playGame(Player& p1, Player& p2){
//    CheckerBoard board;
//    int turns = 0;
//    while(turns < 150){
//        p1.completeTurn(board);
//        if(board.gameOver() || p1.doneGame(board)){
//            //player 1 wins
//            return 1;
//        }
//
//        p1.completeTurn(board);
//        if(board.gameOver()|| p2.doneGame(board)){
//            //player 2 wins
//            return -1;
//        }
//        turns+= 2;
//
//    }
//    return 0;
//}

void recordResults(const json& toWrite){
    std::string path = "../Coefficient_Results/";
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