//
// Created by maxgi on 11/19/2023.
//

#ifndef CHECKERS_MCPLAYER_H
#define CHECKERS_MCPLAYER_H

#include "AiPlayer.h"
#include <cstdlib>
#include <cmath>
#include <chrono>

class MCNode {

private:
    std::shared_ptr<MCNode> parent;
    float UCB;
    float explore;
    float exploit;
    float wins;
    int timesVisited;
    static float coefficient;
    CheckerBoard board;
    std::vector<std::shared_ptr<MCNode>> children;
public:
    MCNode(CheckerBoard);
    MCNode(CheckerBoard, float);
    MCNode();
    MCNode(CheckerBoard, std::shared_ptr<MCNode>);
    MCNode(float, std::shared_ptr<MCNode>);
    MCNode(float);
    void playOutGame(double);
    int findBestUnexplored(int& numMoves, const short& ogPlayer);
    /**
     * Randomly plays out a game, creating the tree as it goes
     * @param numMoves how many moves have currently been played
     * @param ogPlayer The player who has the first move (0 for white, 1 for black)
     * @return An int,
     */
    int rollout(int& numMoves, const short& ogPlayer);
    static int timesPlayed;
    static int player;
    void computeResults(const int&, const short&, const int& numMoves);
    void calcUCB();
    Move getBestChild();
    void clearNode();


};


class MCPlayer : public AiPlayer{
private:
    float coefficient;
    double timeAllowed;
public:
    MCPlayer(double);
    MCPlayer(double, float);
    Move getPlay(const CheckerBoard&) override;
};


#endif //CHECKERS_MCPLAYER_H
