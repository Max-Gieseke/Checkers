#include "../httplib.h"
#include <fstream>
#include <iostream>
#include <filesystem>
#include <sstream>
#include "../include/MCPlayer.h"
#include "../json.hpp"

std::string readFile(const std::string& filePath);
std::string formatMoveResponse(const CheckerBoard& board);
std::string stringifyMove(const Move& move);

int main()
{
    using namespace httplib;
    Server svr;
    CheckerBoard board;
    MCPlayer ai(5);
    svr.Get("/", [](const Request& req, Response& res) {
        std::string fileContent = readFile("../web/main.html");
        res.set_content(fileContent, "text/html");
    });

    svr.Get("/game", [](const Request& req, Response& res) {
        std::string fileContent = readFile("../web/game.html");
        res.set_content(fileContent, "text/html");
    });

    svr.Get("/styles.css", [](const Request& req, Response& res) {
        std::string fileContent = readFile("../web/styles.css");
        res.set_content(fileContent, "text/css");
    });

    svr.Get("/game.js", [](const Request& req, Response& res) {
        std::string fileContent = readFile("../web/game.js");
        res.set_content(fileContent, "text/javascript");
    });

    svr.Get("/main.js", [](const Request& req, Response& res) {
        std::string fileContent = readFile("../web/main.js");
        res.set_content(fileContent, "text/javascript");
    });

    svr.Get("/api/getMove", [&board](const Request& req, Response& res) {
        std::string moves = formatMoveResponse(board);
        res.set_content(moves, "application/json");
    });

    svr.Get("/api/aiTurn", [&board, &ai](const Request& req, Response& res) {
        Move move = ai.getPlay(board);
        std::string moveS = stringifyMove(move);
        res.set_content(moveS, "application/json");
    });

    svr.Get("/api/restart", [&board](const Request& req, Response& res) {
        board = CheckerBoard();
    });

    svr.Post("/api/doTurn", [&board](const Request& req, Response& res){
        json toDo = json::parse(req.body);
        std::cout << std::setw(4) << toDo;

        Move m(toDo["start"], toDo["end"], toDo["jumps"]);
        board = board.doTurn(m);
        std::cout << board;
    });

//    svr.Post("/api/doMove", [&board](const Request& req, Response& res){
//        json toDo = json::parse(req.body);
//        std::cout << std::setw(4) << toDo;
//
//        Move m(toDo["start"], toDo["end"], toDo["jumps"]);
//        board = board.doTurn(m);
//        std::cout << board;
//        std::string moves = formatMoveResponse(board);
//        res.set_content(moves, "application/json");
//    });



    svr.Get("/stop", [&](const Request& req, Response& res) {
        svr.stop();
    });

    svr.listen("localhost", 8080);
}

std::string readFile(const std::string& filePath){
    std::ifstream inFile(filePath);
    if(inFile.is_open()){
        std::ostringstream content;
        content << inFile.rdbuf();
        return content.str();
    }
    std::cout << "Error getting file " << filePath << std::endl;
    return "";
}


std::string formatMoveResponse(const CheckerBoard& board){
    std::vector<Move> moves = JumpTree::possibleMoves(board);
    std::vector<json> all;
    json single;
    for (const auto& m : moves) {
        single["start"] = static_cast<int>(m.getStart());
        single["end"] = static_cast<int>(m.getEnd());
        std::vector<int> removal;
        for(auto& sq : m.getRemove()){
            removal.push_back(static_cast<int>(sq));
        }
        single["jumps"] = removal;
        all.push_back(single);
    }
    json package;
    package["moves"] = all;
    return package.dump();
}


std::string stringifyMove(const Move& move) {
    json all;
    all["start"] = static_cast<int>(move.getStart());
    all["end"] = static_cast<int>(move.getEnd());
    std::vector<int> removal;
    for(auto& sq : move.getRemove()){
        removal.push_back(static_cast<int>(sq));
    }
    all["jumps"] = removal;

    return all.dump();
}