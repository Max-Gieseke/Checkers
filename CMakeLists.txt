cmake_minimum_required(VERSION 3.24)
project(Checkers)

set(CMAKE_CXX_STANDARD 17)

add_executable(MoveTester
        MoveTester.cpp
        Board.cpp Board.h
        MoveTree.cpp MoveTree.h
        Move.cpp Move.h)
