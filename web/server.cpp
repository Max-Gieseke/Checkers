#include "../httplib.h"
#include <fstream>
#include <iostream>
#include <filesystem>

std::string readFile(const std::string& filePath);

int main()
{
    using namespace httplib;

    Server svr;
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