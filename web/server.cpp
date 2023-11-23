#include "../httplib.h"
#include <fstream>
#include <iostream>
#include <filesystem>
#include <sstream>
#include "../include/MCPlayer.h"

std::string readFile(const std::string& filePath);

int main()
{
    using namespace httplib;
    Server svr;
    CheckerBoard board;
    svr.Get("/", [](const Request& req, Response& res) {
        std::string fileContent = readFile("../web/main.html");
        res.set_content(fileContent, "text/html");
    });

    svr.Get("/game", [](const Request& req, Response& res) {
        std::string fileContent = readFile("../web/game.html");
        res.set_content(fileContent, "text/html");
    });

    svr.Get("/styles.css", [](const Request& req, Response& res) {
        std::cout << "Here\n";
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
        std::cout << "Here\n";
        std::vector<Move> moves = JumpTree::possibleMoves(board);
        std::stringstream respStream;
        respStream << "{\"moves\": [";
        for(const auto& m : moves){
            std::cout << m;
            respStream << "{\"start\": " << static_cast<int>(m.getStart()) << ", \"end\": " << static_cast<int>(m.getEnd());
            respStream << ", \"jumps\": [";
            std::cout <<"size "<< m.getRemove().size() << std::endl;
            if(m.getRemove().size() > 0){
                for(int i = 0; i < (m.getRemove().size() - 1); i++) {
                    std::cout << i << std::endl;
                    respStream << static_cast<int>(m.getRemove()[i]) << ", ";
                }
            }
            
            if(m.getRemove().size() >= 1) {
                std::cout << "Herein\n";
                respStream << static_cast<int>(m.getRemove()[m.getRemove().size() -1]);
            }
            if(&m == &moves.back()){
                respStream << "]}";
            }
            else {
                respStream << "]},";
            }
        }
        respStream << "]}";
        res.set_content(respStream.str(), "application/json");
    });



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