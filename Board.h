//
// Created by Max Gieseke on 12/21/2022.
//
#include <string>
#include <vector>
#include <iterator>
#include <queue>
#include "JumpTree.h"
#include "Move.h"
#include "Scores.h"
#include <random>
#include <ctime>
using namespace std;
#ifndef CHECKERS_BOARD_H
#define CHECKERS_BOARD_H


class Board {
    using small = unsigned char;
private:
    small board[32];
    small currentPlayer;
    static bool king(small, small*);

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
    Board(small[], small);
    static void initializeMaps();
    void switchPlayer();
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
    vector<Move> possibleMoves();
    static Board doMove(Move, Board);
    void doMove(Move);
    vector<Move> getJumps(small);
    //vector<small> getStop(small, vector<small>);
    small* doMove(small, small, small, small *, bool& newKing);
    static small maxJumps(vector<Move>);
    void updateBoard(Move move);
    static Board randomBoard();
    small* getBoard();
    small getPlayer();
    friend ostream& operator<<(ostream& out, Board b);
    bool equals(const Board&);
    Board& operator=(const Board&);
    /**
     * Evaluates the board based on the values in the Score Class, positive favors black, negative favors white
     * @return a double showing who the board favors
     */
    double scoreBoard();

};

extern vector<small> whiteMoveMap[32];
extern vector<small> blackMoveMap[32];
extern vector<small> kingMoveMap[32];
extern Scores points;





#endif //CHECKERS_BOARD_H
