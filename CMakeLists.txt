cmake_minimum_required(VERSION 3.24)
project(Checkers)

set(CMAKE_CXX_STANDARD 17)

add_executable(MoveTester
        programs/MoveTester.cpp
        include/Board.cpp include/Board.h
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
        include/Player.h json.hpp)

add_executable(MoveExplorer
        programs/ExplorerTester.cpp
        include/Board.cpp include/Board.h
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
        include/Player.h json.hpp)

add_executable(PlayGame
        programs/PlayVsAI.cpp
        include/Board.cpp include/Board.h
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
        include/Player.h json.hpp)

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
        include/Player.h json.hpp)

add_executable(GeneticAlgorithm
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
        include/Player.h
        json.hpp
        programs/GeneticAlgorithm.cpp)
