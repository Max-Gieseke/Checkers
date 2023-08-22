//
// Created by maxgi on 8/20/2023.
//

#include "Board.h"
#include <iostream>
#include <vector>
#include <random>
#include <ctime>
using namespace std;
using small = unsigned char;
template <typename S>
ostream& operator<<(ostream& os,
                    const vector<S>& vector)
{
    if(vector.size() == 0){
        return os;
    }
    // Printing all the elements
    // using <<
    for(int i = 0; i < vector.size() - 1; i++){
        os << (int)vector[i] << ", ";
    }
    os << (int)vector.back();

    return os;
}

int main(){
    Board::initializeMaps();
    srand(time(nullptr));
    small b1[32];
    Board normal = Board();
    cout << normal;
    cout << "Evaluation: " << normal.scoreBoard() << endl;
    for(int i = 0; i < 32; i++){
        b1[i] = 0;
    }
    b1[13] = 2;
    b1[25] = 2;
    b1[26] = 2;
    b1[17] = 2;
    b1[18] = 2;
    Board test = Board(b1);
    cout << test;
    cout << "Evaluation: " << test.scoreBoard() << endl;
//    for(int i = 0; i < 10; i ++){
//        Board test = Board::randomBoard();
//        cout << "-------------------------------\n Board " << i + 1 << endl;
//        cout << test;
//        cout << "Evaluation: " << test.scoreBoard() << endl;
//        cout << "White Moves" << endl;
//        vector<Move> m1 = test.possibleMoves(0);
//        cout << "Num Moves: " << m1.size() << endl;
//        for(Move m : m1){
//            cout << m;
//        }
//        cout << "Black Moves" << endl;
//        m1 = test.possibleMoves(1);
//        cout << "Num Moves: " << m1.size() << endl;
//        for(Move m : m1){
//            cout << m;
//        }
//        cout << "-------------------------------\n";
//    }


    return 0;
}
