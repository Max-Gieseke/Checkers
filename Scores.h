//
// Created by maxgi on 8/22/2023.
//

#ifndef CHECKERS_SCORES_H
#define CHECKERS_SCORES_H


class Scores {
public:
    static Scores& getInstance();
    double kingVal;
    double pawnVal;
    double rankBonus;
    double noPieces;
private:
    Scores();

};


#endif //CHECKERS_SCORES_H
