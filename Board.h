//
// Created by maxgi on 12/21/2022.
//
#include <string>
#include <vector>
#include <iterator>
#include <hash_map>
#include <queue>
#include "MoveTree.h"
#include "Move.h"
#include <random>
#include <ctime>
using namespace std;
#ifndef CHECKERS_BOARD_H
#define CHECKERS_BOARD_H


class Board {
    using small = unsigned char;
private:
    small board[32];
    bool king(small, small*);

    /*
     * Pieces:
     * blank = 0
     * Black piece = 1
     * White piece = 2
     * Black king = 3
     * White king = 4
     * White turn = 0
     * Black turn = 1
     */


public:
    Board(); // Initialize checkerboard with black on squares 0-11 and red on squares 20-31
    Board(small[]);
    static void initializeMaps();
    /*
     * Moves are kept track of through an array of strings
     * where each move is "xyza", where x is start square, y is square to move to,
     * and z and a are optional squares to remove a piece from
     * first element in array is how long it is
     */
    small getColor(small);
    vector<small>* getMoveMap(small);
    /**
     * Returns all jumps from a single square
     * @param square the starting square
     * @param board the board to look at
     * @return a vector of pairs where first is the jumped and second is the end square
     */
    vector<pair<small, small>> singleJump(small square, small* board);
    int finalJump(small, small);
    vector<Move> possibleMoves(small);
    small* doMove(Move, small[]);
    void doMove(Move);
    vector<Move> getJumps(small);
    //vector<small> getStop(small, vector<small>);
    small* doMove(small, small, small, small *, bool& newKing);
    static small maxJumps(vector<Move>);
    void updateBoard(Move move);
    static Board randomBoard();
    small* getBoard();
    friend ostream& operator<<(ostream& out, Board b);

};

extern vector<small> whiteMoveMap[32];
extern vector<small> blackMoveMap[32];
extern vector<small> kingMoveMap[32];





#endif //CHECKERS_BOARD_H
