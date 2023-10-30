//
// Created by Max Gieseke on 12/21/2022.
//
#include <string>
#include <iterator>
#include <queue>
#include "JumpTree.h"
#include "Scores.h"
#include <random>
#include <ctime>
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
    Board(const small[], small);
    static void initializeMaps();
    void switchPlayer();
    static small getColor(small);
    static std::vector<small>* getMoveMap(small);
    /**
     * Returns all jumps from a single square
     * @param square the starting square
     * @param board the board to look at
     * @return a vector of pairs where first is the jumped and second is the end square
     */
    static std::vector<std::pair<small, small>> singleJump(small square, small* board);
    static int finalJump(small, small);
    std::vector<Move> possibleMoves();
    static Board doMove(Move, Board);
    void doMove(Move);
    std::vector<Move> getJumps(small);
    //vector<small> getStop(small, vector<small>);
    static small* doMove(small, small, small, small *, bool& newKing);
    static small maxJumps(std::vector<Move>);
    void updateBoard(const Move& move);
    static Board randomBoard();
    small* getBoard();
    small getPlayer() const;
    friend std::ostream& operator<<(std::ostream& out, Board b);
    bool equals(const Board&);
    Board& operator=(const Board&);
    /**
     * Evaluates the board based on the values in the Score Class, positive favors black, negative favors white
     * @return a double showing who the board favors
     */
    double scoreBoard();

};

extern std::vector<small> whiteMoveMap[32];
extern std::vector<small> blackMoveMap[32];
extern std::vector<small> kingMoveMap[32];
extern Scores points;





#endif //CHECKERS_BOARD_H
