//
// Created by maxgi on 11/19/2023.
//

#include "../include/MCPlayer.h"


int MCNode::timesPlayed = 0;
MCNode::MCNode(CheckerBoard board) {
    parent = nullptr;
    wins = 0;
    timesVisited = 0;
    this->board = board;
}

MCNode::MCNode() {
    this->parent = nullptr;
    this->UCB = 0;
    timesVisited = 0;
    wins = 0;
    board = CheckerBoard();
}

MCNode::MCNode(CheckerBoard board, std::shared_ptr<MCNode> parent) {
    this->board = board;
    this->parent = parent;
    this->UCB = -1;
    timesVisited = 0;
    wins = 0;
}

MCNode::MCNode(float UCB, std::shared_ptr<MCNode> parent) {
    this->parent = parent;
    this->UCB = UCB;
    wins = 0;
    timesVisited = 0;
}

MCNode::MCNode(float UCB) {
    this->parent = nullptr;
    this->UCB = UCB;
    wins = 0;
    timesVisited = 0;
}

void MCNode::playOutGame(double timeAllowed) {
    MCNode::timesPlayed = 1;
    int toSixth = 1000000;
    short player = this->board.getPlayer();
    auto start = std::chrono::high_resolution_clock::now();
    auto duration = 0;
    while(duration < (timeAllowed * toSixth)) {
        int result = findBestUnexplored(0, player);
        computeResults(result, player);
        duration = std::chrono::duration_cast<std::chrono::microseconds>(
                std::chrono::high_resolution_clock::now() - start).count();
        std::cout << "Played " << MCNode::timesPlayed << " games\n";
        MCNode::timesPlayed++;
    }
}

/*
 * TODO:
 * add code to adjust UCB when rollout and unexplored are done
 * (set result to tmp variable, update win and times, UCB = calcCB, return)
 */

int MCNode::findBestUnexplored(int numMoves, const short& ogPlayer) {
    this->timesVisited++;
    if(board.gameOver()){
        int result = -2 * board.getPlayer() + 1;
        computeResults(result, ogPlayer);
        return result;
    }
    if(numMoves == 150){
        computeResults(0, ogPlayer);
        return 0;
    }
    std::shared_ptr<MCNode> next;
    float best_UCB;
    int result;
    if (children.empty()) {
        std::vector<Move> moves = JumpTree::possibleMoves(board);
        for(auto& m : moves) {
            children.push_back(std::make_shared<MCNode>(
                    MCNode(board.doTurn(m), std::make_shared<MCNode>(*this))));
        }
    }
    for(auto& child : children){
        if(child->UCB == -1){
            result = child->rollout(++numMoves, ogPlayer);
            computeResults(result, ogPlayer);
            return result;
        }
        if(child->UCB > best_UCB){
            best_UCB = child->UCB;
            next = child;
        }
    }
    int res =  next->findBestUnexplored(numMoves++, ogPlayer);
    computeResults(res, ogPlayer);
    return res;
}
//return -1 if white wins, 1 if black wins
int MCNode::rollout(int numMoves, const short& ogPlayer) {
    this->timesVisited++;
    if(board.gameOver()){
        int result = -2 * board.getPlayer() + 1;
        //black was og and won or white was and won
        computeResults(result, ogPlayer);
        return result;
    }
    if(numMoves == 150){
        computeResults(0, ogPlayer);
        return 0;
    }
    std::vector<Move> moves = JumpTree::possibleMoves(board);
    for(auto& m : moves){
        children.push_back(std::make_shared<MCNode>(
                MCNode(board.doTurn(m), std::make_shared<MCNode>(*this))));
    }
    int randomIdx = rand() % children.size();
    int res = children[randomIdx]->rollout(++numMoves, ogPlayer);
    computeResults(res, ogPlayer);
    return res;

}

float MCNode::calcUCB() {
    if(parent == nullptr){ //if we are root node, no parent
        return 0;
    }
    return wins / MCNode::timesPlayed +
            std::sqrt(std::log(parent->timesVisited) / MCNode::timesPlayed);
}


void MCNode::computeResults(const short & result, const short & ogPlayer) {
    if(result == 0){
        this->wins += 0.5;
        this->UCB = this->calcUCB();
    }
    else if ((ogPlayer == result) || (ogPlayer == result + 1)){
        this->wins++;
        this->UCB = this->calcUCB();
    }
    else {
        this->UCB = this->calcUCB();
    }
}
//Got to change board to move
Move MCNode::getBestChild() {
    float bestUCB = 0;
    Move bestMove;
    std::vector<Move> moves = JumpTree::possibleMoves(board);
    for(const auto& child : this->children){
        if (child->UCB > bestUCB){
            bestUCB = child->UCB;
            for(const Move& m : moves) {
                CheckerBoard tmp = this->board.doTurn(m);
                if (tmp == child->board){
                    bestMove = m;
                    break;
                }
            }
        }
    }
    return bestMove;
}


void MCNode::clearNode() {
    if(children.empty()){
        parent.reset();
        return;
    }
    for(auto & child : children){
        child->clearNode();
    }
    parent.reset();
}



MCPlayer::MCPlayer(double timePerMove) {
    timeAllowed = timePerMove;
}

Move MCPlayer::getPlay(const CheckerBoard& board) {
    MCNode start(board);
    start.playOutGame(this->timeAllowed);
    Move best = start.getBestChild();
    start.clearNode();
    return best;
}


