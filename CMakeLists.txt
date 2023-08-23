cmake_minimum_required(VERSION 3.24)
project(Checkers)

set(CMAKE_CXX_STANDARD 17)

add_executable(MoveTester
        MoveTester.cpp
        Board.cpp Board.h
        JumpTree.cpp JumpTree.h
        Move.cpp Move.h
        Scores.cpp Scores.h)

add_executable(MoveExplorer
        ExplorerTester.cpp
        Board.cpp Board.h
        JumpTree.cpp JumpTree.h
        Move.cpp Move.h
        ZobristHash.cpp ZobristHash.h
        TranspositionTable.cpp TranspositionTable.h
        Scores.cpp Scores.h
        MoveTree.cpp MoveTree.h MoveNode.cpp MoveNode.h)
