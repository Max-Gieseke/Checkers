//
// Created by maxgi on 8/20/2023.
//

#ifndef CHECKERS_MOVE_H
#define CHECKERS_MOVE_H
#include <vector>
#include <iostream>
using small = unsigned char;

class Move {
private:
    small start;
    small end;
    std::vector<small> remove;
public:
    Move();
    Move(small, small);
    Move(small, small, std::vector<small>);
    void addJump(small);
    small getStart();
    small getEnd();
    std::vector<small> getRemove();
    friend std::ostream& operator<<(std::ostream& out, Move m);
    Move& operator=(const Move&);
    bool equals(const Move&);
};


#endif //CHECKERS_MOVE_H
