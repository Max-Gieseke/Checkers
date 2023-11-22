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
    [[nodiscard]] small getStart() const;
    [[nodiscard]] small getEnd() const;
    [[nodiscard]] std::vector<small> getRemove() const;
    friend std::ostream& operator<<(std::ostream& out, const Move& m);
    [[nodiscard]] bool isCapture() const;
    Move& operator=(const Move&);
    bool equals(const Move&);
};


#endif //CHECKERS_MOVE_H
