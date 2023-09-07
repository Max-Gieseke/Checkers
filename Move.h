//
// Created by maxgi on 8/20/2023.
//

#ifndef CHECKERS_MOVE_H
#define CHECKERS_MOVE_H
#include <vector>
#include <iostream>
using namespace std;
using small = unsigned char;

class Move {
private:
    small start;
    small end;
    vector<small> remove;
public:
    Move();
    Move(small, small);
    Move(small, small, vector<small>);
    void addJump(small);
    small getStart();
    small getEnd();
    vector<small> getRemove();
    friend ostream& operator<<(ostream& out, Move m);
    Move& operator=(const Move&);
    bool equals(const Move&);
};


#endif //CHECKERS_MOVE_H
