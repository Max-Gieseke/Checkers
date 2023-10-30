//
// Created by maxgi on 8/20/2023.
//

#include "Board.h"

#include <ctime>
using small = unsigned char;
template <typename S>
std::ostream& operator<<(std::ostream& os, const std::vector<S>& vector) {
    if(vector.size() == 0){
        return os;
    }
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
    std::cout << normal;
    std::cout << "Evaluation: " << normal.scoreBoard() << std::endl;
    for(int i = 0; i < 32; i++){
        b1[i] = 0;
    }
    b1[25] = 2;
    b1[20] = 1;
    b1[26] = 2;
    Board test = Board();
    std::cout << test;
    std::cout << "Evaluation: " << test.scoreBoard() << std::endl;
    std::vector<Move> m1 = test.possibleMoves();
    std::cout << "Num Moves: " << m1.size() << std::endl;
    for(Move m : m1){
        std::cout << m;
    }
//    for(int i = 0; i < 10; i ++){
//        Board test = Board::randomBoard();
//        cout << "-------------------------------\n Board " << i + 1 << endl;
//        cout << test;
//        cout << "Evaluation: " << test.scoreBoard() << endl;
//        cout << "White Moves" << endl;
//        vector<Move> m1 = test.possibleMoves();
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
