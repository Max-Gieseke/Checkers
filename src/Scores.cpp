//
// Created by maxgi on 8/22/2023.
//

#include "../include/Scores.h"
//Temporary testing scores
Scores::Scores() {
    kingVal = 6.0;
    pawnVal = 3.0;
    rankBonus = 0.25;
    noPieces = 100.00;

}

Scores &Scores::getInstance() {
    static Scores instance;
    return instance;
}
