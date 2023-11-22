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
    int wins;
    int timesVisited;
    CheckerBoard board;
    std::vector<std::shared_ptr<MCNode>> children;
public:
    MCNode(CheckerBoard);
    MCNode();
    MCNode(CheckerBoard, std::shared_ptr<MCNode>);
    MCNode(float, std::shared_ptr<MCNode>);
    MCNode(float);
    void playOutGame(double);
    int findBestUnexplored(int, const short&);
    int rollout(int, const short&);
    static int timesPlayed;
    static int player;
    void computeResults(const short&, const short&);
    float calcUCB();
    Move getBestChild();
    void clearNode();


};


class MCPlayer : public AiPlayer{
private:
    double timeAllowed;
public:
    MCPlayer(double);
    Move getPlay(const CheckerBoard&) override;
};


#endif //CHECKERS_MCPLAYER_H
