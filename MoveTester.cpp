//
// Created by maxgi on 8/20/2023.
//

#include "Board.h"
#include <iostream>
#include <vector>
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
//    for(int i = 0; i < 32; i++){
//        cout << "Black " << i << ": " << blackMoveMap[i] << endl;
//        cout << "White " << i << ": " << whiteMoveMap[i] << endl;
//        cout << "King " << i << ": " << kingMoveMap[i] << endl;
//    }
    small b1[32];
    for(int i = 0; i < 32; i++){
        b1[i] = 0;
    }
    b1[13] = 1;
    b1[25] = 2;
    b1[26] = 2;
    b1[17] = 1;
    b1[18] = 2;
    Board test = Board();
    cout << test;
    vector<Move> m1 = test.possibleMoves(1);
    for(Move m : m1){
        cout << m;
    }


    return 0;
}
