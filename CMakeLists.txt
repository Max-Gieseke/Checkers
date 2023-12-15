cmake_minimum_required(VERSION 3.24)
project(Checkers)

set(CMAKE_CXX_STANDARD 17)
# set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS}")

add_executable(MoveTester
        programs/MoveTester.cpp
        src/JumpTree.cpp include/JumpTree.h
        src/Move.cpp include/Move.h
        src/ZobristHash.cpp include/ZobristHash.h
        src/TranspositionTable.cpp include/TranspositionTable.h
        src/Scores.cpp include/Scores.h
        src/CheckerBoard.cpp include/CheckerBoard.h
        src/CheckerMoveMaps.cpp include/CheckerMoveMaps.h
        src/JumpNode.cpp include/JumpNode.h
        src/AiPlayer.cpp include/AiPlayer.h
        src/HumanPlayer.cpp include/HumanPlayer.h
        include/Player.h json.hpp src/MCPlayer.cpp include/MCPlayer.h)

add_executable(MoveExplorer
        programs/ExplorerTester.cpp
        src/JumpTree.cpp include/JumpTree.h
        src/Move.cpp include/Move.h
        src/ZobristHash.cpp include/ZobristHash.h
        src/TranspositionTable.cpp include/TranspositionTable.h
        src/Scores.cpp include/Scores.h
        src/CheckerBoard.cpp include/CheckerBoard.h
        src/CheckerMoveMaps.cpp include/CheckerMoveMaps.h
        src/JumpNode.cpp include/JumpNode.h
        src/AiPlayer.cpp include/AiPlayer.h
        src/HumanPlayer.cpp include/HumanPlayer.h
        include/Player.h json.hpp src/MCPlayer.cpp include/MCPlayer.h)

add_executable(AITest
        programs/AIvsAI.cpp
        src/JumpTree.cpp include/JumpTree.h
        src/Move.cpp include/Move.h
        src/ZobristHash.cpp include/ZobristHash.h
        src/TranspositionTable.cpp include/TranspositionTable.h
        src/Scores.cpp include/Scores.h
        src/CheckerBoard.cpp include/CheckerBoard.h
        src/CheckerMoveMaps.cpp include/CheckerMoveMaps.h
        src/JumpNode.cpp include/JumpNode.h
        src/AiPlayer.cpp include/AiPlayer.h
        src/HumanPlayer.cpp include/HumanPlayer.h
        include/Player.h json.hpp src/MCPlayer.cpp include/MCPlayer.h
        src/RandomPlayer.cpp
        include/RandomPlayer.h)

add_executable(GeneticAlgo
        programs/GeneticAlgorithm.cpp
        src/JumpTree.cpp include/JumpTree.h
        src/Move.cpp include/Move.h
        src/ZobristHash.cpp include/ZobristHash.h
        src/TranspositionTable.cpp include/TranspositionTable.h
        src/Scores.cpp include/Scores.h
        src/CheckerBoard.cpp include/CheckerBoard.h
        src/CheckerMoveMaps.cpp include/CheckerMoveMaps.h
        src/JumpNode.cpp include/JumpNode.h
        src/AiPlayer.cpp include/AiPlayer.h
        include/Player.h json.hpp)

add_executable(WebServer
        web/server.cpp
        src/JumpTree.cpp include/JumpTree.h
        src/Move.cpp include/Move.h
        src/ZobristHash.cpp include/ZobristHash.h
        src/TranspositionTable.cpp include/TranspositionTable.h
        src/Scores.cpp include/Scores.h
        src/CheckerBoard.cpp include/CheckerBoard.h
        src/CheckerMoveMaps.cpp include/CheckerMoveMaps.h
        src/JumpNode.cpp include/JumpNode.h
        src/AiPlayer.cpp include/AiPlayer.h
        src/HumanPlayer.cpp include/HumanPlayer.h
        include/Player.h
        json.hpp
        src/MCPlayer.cpp include/MCPlayer.h
        httplib.h)

add_executable(CoefficientFinder
        programs/CoefficientFinder.cpp
        src/JumpTree.cpp include/JumpTree.h
        src/Move.cpp include/Move.h
        src/ZobristHash.cpp include/ZobristHash.h
        src/TranspositionTable.cpp include/TranspositionTable.h
        src/Scores.cpp include/Scores.h
        src/CheckerBoard.cpp include/CheckerBoard.h
        src/CheckerMoveMaps.cpp include/CheckerMoveMaps.h
        src/JumpNode.cpp include/JumpNode.h
        src/AiPlayer.cpp include/AiPlayer.h
        src/MCPlayer.cpp include/MCPlayer.h
        include/Player.h json.hpp)

add_executable(Tournament
        programs/Tournament.cpp
        src/JumpTree.cpp include/JumpTree.h
        src/Move.cpp include/Move.h
        src/ZobristHash.cpp include/ZobristHash.h
        src/TranspositionTable.cpp include/TranspositionTable.h
        src/Scores.cpp include/Scores.h
        src/CheckerBoard.cpp include/CheckerBoard.h
        src/CheckerMoveMaps.cpp include/CheckerMoveMaps.h
        src/JumpNode.cpp include/JumpNode.h
        src/AiPlayer.cpp include/AiPlayer.h
        src/MCPlayer.cpp include/MCPlayer.h
        src/RandomPlayer.cpp include/RandomPlayer.h
        include/Player.h json.hpp)

if (WIN32)
    target_link_libraries(WebServer PRIVATE wsock32 ws2_32)
endif()
target_compile_options(MoveExplorer PRIVATE -O3)