//
// Created by maxgi on 11/15/2023.
//
#include "../include/AiPlayer.h"
#include <random>
#include <filesystem>
#include <fstream>
#include <thread>
#include <future>
using json = nlohmann::json;

/**
 * Will take in a Score object and a float and return a JSON object
 * that represents the values for a new score object where each value
 * is a from a random number centered at the last score and confined to
 * values only differing from that score by the percent given by the float
 * @param range a float representing a percent that the number will
 * be between
 * @param curScore the Score object to make the new data from
 * @return a json object that will hold the values for a new score object
 */

int playRoundForPlayer(std::vector<std::pair<float, AiPlayer>>& allPlayers, int player);
json createNewScores(const Scores& curScore, float range);

std::vector<std::pair<float, AiPlayer>> loadGeneration(json lastGen);

json generateFullyRandomScores();
void getUpperAndLower(float& upper, float& lower, float start, float range);

void recordResults(std::vector<std::pair<float, AiPlayer>>& gen, int genNumber);

json playerToJson(const std::pair<float, AiPlayer>& player);


std::vector<std::pair<float, AiPlayer>> createNextGeneration(std::vector<std::pair<float, AiPlayer>>& pastGen, int numGens);

std::vector<std::pair<float, AiPlayer>> loadFromPastGeneration(int& curGen);

/**
 * Plays a game between two ais, draws after 150 move
 * @param ai1 player one
 * @param ai2 player two
 * @return 1 if player 1 wins, -1 if player 2 wins, 0 if draw
 */
double playGame(AiPlayer& ai1, AiPlayer& ai2);

void doGeneration(std::vector<std::pair<float, AiPlayer>>& curGen);

void doAllGenerations();


int DEPTH = 5;
int GEN_SIZE = 25;
std::default_random_engine ENGINE(12);

int main() {
    doAllGenerations();
}



void getUpperAndLower(float& upper, float& lower, float start, float range){
    //No negative values
    if(start < 0){
        upper = -start;
        lower = 0;
    }
    else if (start == 0){
        upper = range;
        lower = 0;
    }
    else {
        upper = start + start * range + 1;
        lower = std::fmax(start - start * range - 1, 0);
    }
}

json createNewScores(const Scores& curScore, float range){
    float upperBound;
    float lowerBound;
    json newData;
    //pawnVal
    getUpperAndLower(upperBound, lowerBound, curScore.pawnVal, range);
    std::uniform_real_distribution<float> uniform(lowerBound,upperBound);
    newData["pawnVal"] = uniform(ENGINE);
    //kingVal
    getUpperAndLower(upperBound, lowerBound, curScore.kingVal, range);
    uniform = std::uniform_real_distribution<float>(lowerBound,upperBound);
    newData["kingVal"] = uniform(ENGINE);
    //rankBonus
    getUpperAndLower(upperBound, lowerBound, curScore.rankBonus, range);
    uniform = std::uniform_real_distribution<float>(lowerBound,upperBound);
    newData["rankBonus"] = uniform(ENGINE);
    //win
//    getUpperAndLower(upperBound, lowerBound, curScore.win, range);
//    uniform = std::uniform_real_distribution<float>(lowerBound,upperBound);
    newData["win"] = INT32_MAX;

    return newData;
}

double playGame(AiPlayer& ai1, AiPlayer& ai2){
    CheckerBoard board;
    int turns = 0;
    TranspositionTable pastPositions;
    while(turns < 150){
        ai1.completeTurn(board, pastPositions);
        if(board.gameOver() || Player::doneGame(board, pastPositions)){
            return 1;
        }

        ai2.completeTurn(board, pastPositions);
        if(board.gameOver() || Player::doneGame(board, pastPositions)){
            return -1;
        }
        turns+= 2;

    }
//    std::cout << "No Winner\n";
//    std::cout << board;
    return board.scoreBoard(Scores());
}


json generateFullyRandomScores(){
    json newData;
    std::uniform_real_distribution<float> uniformVal(0, 10);
    newData["pawnVal"] = uniformVal(ENGINE);
    newData["kingVal"] = uniformVal(ENGINE);

    std::uniform_real_distribution<float> uniformBonus(0, 1);
    newData["rankBonus"] = uniformVal(ENGINE);
    std::uniform_real_distribution<float> uniformWin(100, 1000);
    newData["win"] = uniformVal(ENGINE);
    return newData;
}

std::vector<std::pair<float, AiPlayer>> createNextGeneration(std::vector<std::pair<float, AiPlayer>>& pastGen, int numGens){
    sort(pastGen.begin(), pastGen.end(), [](const auto& a, const auto& b) {
        return a.first > b.first;
    });
    std::vector<std::pair<float, AiPlayer>> nextGen(GEN_SIZE);
    nextGen[0] = pastGen[0];
    nextGen[0].first = 0;
    for(int i = 1; i < 4; i++){
        nextGen[i] = std::pair<float, AiPlayer>(0, AiPlayer(DEPTH, Scores(createNewScores(pastGen[0].second.getScoring(), 0.2))));
    }
    for(int i = 4; i < 6; i++){
        nextGen[i] = std::pair<float, AiPlayer>(0, AiPlayer(DEPTH, Scores(createNewScores(pastGen[0].second.getScoring(), 0.5))));
    }
    for(int i = 6; i < 10; i++){
        nextGen[i] = std::pair<float, AiPlayer>(0, AiPlayer(DEPTH, Scores(createNewScores(pastGen[1].second.getScoring(), 1))));
    }
    for(int j = 2; j < 7; j++){
        for(int i = 0; i < 3; i++){
            int idx = i + 10 + 3 * (j - 2);
            nextGen[idx] = std::pair<float, AiPlayer>(0, AiPlayer(DEPTH, Scores(createNewScores(pastGen[j].second.getScoring(), 1))));
        }
    }
    return nextGen;
}

int playRoundForPlayer(std::vector<std::pair<float, AiPlayer>>& allPlayers, int player){
    int gamesPlayed = 0;
    for(int i = player + 1; i < allPlayers.size(); i++){
        double res = playGame(allPlayers[player].second, allPlayers[i].second);
        if(res > 0){
//            std::cout << "Black won\n";
            allPlayers[player].first++;
        }
        else if (res < 0){
            //std::cout << "White won\n";
            allPlayers[i].first++;
        }
        else {
            //std::cout << "Draw\n";
            allPlayers[player].first += 0.5;
            allPlayers[i].first += 0.5;
        }
        //Where j is black
        res = playGame(allPlayers[i].second, allPlayers[player].second);
        if(res > 0){
            //std::cout << "Black won 2\n";
            allPlayers[i].first++;
        }
        else if (res < 0){
            //std::cout << "White won 2\n";
            allPlayers[player].first++;
        }
        else {
            //std::cout << "Draw2\n";
            allPlayers[player].first += 0.5;
            allPlayers[i].first += 0.5;
        }
        gamesPlayed += 2;
    }
    std::cout << std::fixed << std::setprecision(2) << (gamesPlayed * 1.0) / 600 * 100 << "\n";
    return gamesPlayed;
}


void doGeneration(std::vector<std::pair<float, AiPlayer>>& curGen){
    // unsigned int threads = std::thread::hardware_concurrency() - 2;
    std::vector<std::future<int>> futures;
    int count = 0;
    float total = curGen.size() * (curGen.size() - 1);
    for(int i = 0; i < curGen.size(); i++){
       // playRoundForPlayer(curGen, i);
        futures.push_back(std::async(std::launch::async, playRoundForPlayer, std::ref(curGen), i));
    }
    for(auto& future : futures){
        count += future.get();
        std::cout << (count * 1.0) / total << "% done\n";
    }
}

std::vector<std::pair<float, AiPlayer>> loadGeneration(json lastGen){
    std::vector<std::pair<float, AiPlayer>> generation;
    for(json& player : lastGen){
        generation.emplace_back(player["Result"], AiPlayer(DEPTH, Scores(player["Parameters"])));
    }
    return generation;
}


void doAllGenerations(){
    int gen = 0;
    std::vector<std::pair<float, AiPlayer>> generation = loadFromPastGeneration(gen);
    gen++;
    while(true) {
        doGeneration(generation);
        recordResults(generation, gen);
        generation = createNextGeneration(generation, gen);
        std::cout << "Generation " <<gen++ << " finished\n";
    }
}

json playerToJson(const std::pair<float, AiPlayer>& player){
    json newData;
    newData["Result"] = player.first;
    newData["Parameters"] = player.second.getScoring().scoresToJson();
    return newData;
}


void recordResults(std::vector<std::pair<float, AiPlayer>>& gen, int genNumber){
    std::string newDir = "Generation_" + std::to_string(genNumber);
    std::string path = "../Generation_Results/" + newDir;
    std::filesystem::create_directory(path);
    path = path + "/results.json";

    json toWrite;
    for(int i = 0; i < gen.size(); i++){
        std::string name = "Player_" + std::to_string(i + 1);
        toWrite[name] = playerToJson(gen[i]);
    }

    std::ofstream oFile(path);
    if(oFile.is_open()){
        oFile << std::setw(4) << toWrite;
    }
    else {
        std::cerr << "Error opening file\n";
    }
}


std::vector<std::pair<float, AiPlayer>> loadFromPastGeneration(int& curGen){
    std::string pathToGenerations = "../Generation_Results/";
    curGen = 0;
    for(const auto& entry : std::filesystem::directory_iterator(pathToGenerations)){
        std::string fileName = entry.path().filename().string();
        int num = std::stoi(fileName.substr(fileName.find('_') + 1));
        if(num > curGen){
            curGen = num;
        }
    }
    if(curGen == 0){
        std::cout << "Generating random starting generation\n";
        std::vector<AiPlayer> tmp;
        std::vector<std::pair<float, AiPlayer>> generation;
        for(int i = 0; i < GEN_SIZE; i++){
            tmp.emplace_back(DEPTH, Scores(generateFullyRandomScores()));
            generation.emplace_back(0, AiPlayer(DEPTH, Scores(generateFullyRandomScores())));
        }
        return generation;
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

    std::vector<std::pair<float, AiPlayer>> pastGeneration = loadGeneration(lastGen);
    std::cout << "Loaded generation " << curGen << std::endl;
    return createNextGeneration(pastGeneration, curGen);
}

