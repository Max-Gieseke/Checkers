//
// Created by maxgi on 11/19/2023.
//

#include "../include/MCPlayer.h"

float MCNode::coefficient = -50;
int MCNode::timesPlayed = 0;
MCNode::MCNode(CheckerBoard board) {
    parent = nullptr;
    wins = 0;
    timesVisited = 0;
    this->board = board;
}

MCNode::MCNode(CheckerBoard board, float coValue) {
    parent = nullptr;
    wins = 0;
    timesVisited = 0;
    this->board = board;
    MCNode::coefficient = coValue;
}

MCNode::MCNode() : children() {
    this->parent = nullptr;
    this->UCB = -1;
    timesVisited = 0;
    wins = 0;
    board = CheckerBoard();
}

MCNode::MCNode(CheckerBoard board, std::shared_ptr<MCNode> parent) : children() {
    this->board = board;
    this->parent = parent;
    this->UCB = -1;
    timesVisited = 0;
    wins = 0;
}

MCNode::MCNode(float UCB, std::shared_ptr<MCNode> parent) : children() {
    this->parent = parent;
    this->UCB = UCB;
    wins = 0;
    timesVisited = 0;
}

MCNode::MCNode(float UCB) : children() {
    this->parent = nullptr;
    this->UCB = UCB;
    wins = 0;
    timesVisited = 0;
}

void MCNode::playOutGame(double timeAllowed, TranspositionTable& pastPositions) {
    MCNode::timesPlayed = 1;
    int toSixth = 1000000;
    short player = this->board.getPlayer();
    auto start = std::chrono::high_resolution_clock::now();
    auto duration = 0;
    while(duration < (timeAllowed * toSixth)) {
        int totMoves = 0;
        int result = findBestUnexplored(totMoves, player, pastPositions);
        duration = std::chrono::duration_cast<std::chrono::microseconds>(
                std::chrono::high_resolution_clock::now() - start).count();
        MCNode::timesPlayed++;
    }
}


int MCNode::findBestUnexplored(int& numMoves, const short& ogPlayer, TranspositionTable& pastPositions) {
    this->timesVisited++;
    if(board.gameOver()){
        //Will have 0 for white win, 1 for black
        int result = 1 - board.getPlayer();
        computeResults(result, ogPlayer, numMoves);
        return result;
    }
    if (pastPositions.getDepth(board) == 3) {
        computeResults(0, ogPlayer, numMoves);
        return 0;
    }
    if (children.empty()) {
        std::vector<Move> moves = JumpTree::possibleMoves(board);
        if(moves.empty()){
            //Will have 0 for white win, 1 for black
            int result = 1 - board.getPlayer();
            computeResults(result, ogPlayer, numMoves);
            return result;
        }
        for(auto& m : moves) {
            children.push_back(std::make_shared<MCNode>(
                    MCNode(board.doTurn(m), std::make_shared<MCNode>(*this))));
        }
    }
    std::shared_ptr<MCNode> next;
    float best_UCB = -10000;
    int result;
    for(auto& child : children){
        if(child->UCB == -1){
            result = child->rollout(++numMoves, ogPlayer, pastPositions);
            computeResults(result, ogPlayer, numMoves);
            return result;
        }
        else if(child->UCB > best_UCB){
            best_UCB = child->UCB;
            next = child;
        }
    }
    int res =  next->findBestUnexplored(++numMoves, ogPlayer, pastPositions);
    computeResults(res, ogPlayer, numMoves);
    return res;
}


int MCNode::rollout(int& numMoves, const short& ogPlayer, TranspositionTable& pastPositions) {
    this->timesVisited++;
    if(board.gameOver()){
        //Will have 0 for white win, 1 for black
        int result = 1 - board.getPlayer();
        //black was og and won or white was and won
        computeResults(result, ogPlayer, numMoves);
        return result;
    }
    if (pastPositions.getDepth(board) == 3) {
        computeResults(0, ogPlayer, numMoves);
        return 0;
    }
    std::vector<Move> moves = JumpTree::possibleMoves(board);
    //No moves mean other player won
    if(moves.empty()){
        //Will have 0 for white win, 1 for black
        int result = 1 - board.getPlayer();
        //black was og and won or white was and won
        computeResults(result, ogPlayer, numMoves);
        return result;
    }
    for(auto& m : moves){
        children.push_back(std::make_shared<MCNode>(
                MCNode(board.doTurn(m), std::make_shared<MCNode>(*this))));
    }
    int randomIdx = rand() % children.size();
    int res = children[randomIdx]->rollout(++numMoves, ogPlayer, pastPositions);
    computeResults(res, ogPlayer, numMoves);
    return res;

}

void MCNode::calcUCB() {
    if(parent == nullptr){ //if we are root node, no parent
        return;
    }
    float encTerm = 0;
    if(parent->timesVisited == 1){
        encTerm = 1;
    }
    exploit = (static_cast<float>(wins) / static_cast<float>(timesVisited));
    explore = coefficient * std::sqrt(std::log(static_cast<float>(parent->timesVisited) + encTerm) / timesVisited);
    float tmp = exploit + explore;
    this->UCB = tmp;

}


void MCNode::computeResults(const int & result, const short & ogPlayer, const int& numMoves) {
    //If ogPlayer's turn, then the other player will be choosing move, so UCB should rate games where opp wins as better
    if (result == 0) {
        this->wins += 0.3;
        this->calcUCB();
    }
    else if (board.getPlayer() == ogPlayer) {
        if (ogPlayer == result){
            this->calcUCB();
        }
        else {
            this->wins += std::max(1 - (numMoves / 100.0), 0.6);
            this->calcUCB();
        }
    }
    // If the node is for the other player, then we should count the wins for
    // ogPlayer as wins since that is how the next move will be decided
    else {
        if (ogPlayer == result){
            this->wins += std::max(1 - (numMoves / 100.0), 0.6);
            this->calcUCB();
        }
        else {
            this->calcUCB();
        }
    }
}
//Choose off of exploitation
Move MCNode::getBestChild() {
    float bestExploit = 0;
    std::vector<Move> moves = JumpTree::possibleMoves(board);
    Move bestMove = moves[0];
    for(const auto& child : this->children){
        double rate = static_cast<double>(child->wins) / child->timesVisited;
        if (rate > bestExploit){
            bestExploit = rate;
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
    coefficient = 2;
}

MCPlayer::MCPlayer(double timePerMove, float coefficient) {
    timeAllowed = timePerMove;
    this->coefficient = coefficient;
}

Move MCPlayer::getPlay(const CheckerBoard& board, TranspositionTable& pastPositions) {
    MCNode start(board, coefficient);
    start.playOutGame(this->timeAllowed, pastPositions);
    Move best = start.getBestChild();

    start.clearNode();
    return best;
}


