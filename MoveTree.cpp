////
//// Created by maxgi on 8/22/2023.
////
//
//#include "MoveTree.h"
//
//MoveTree::MoveTree() {
//}
//
////MoveTree::MoveTree(CheckerBoard top) {
////    root = std::make_shared<MoveNode>(top);
////}
////
////MoveTree::MoveTree(CheckerBoard b, int depthSearched, double score, std::shared_ptr<MoveNode> p) {
////    root = std::make_shared<MoveNode>(b, depthSearched, score, p, Move());
////}
//
//// MoveTree::~MoveTree() {
////     delete root;
//// }
//
////std::pair<double, Move> MoveTree::exploreTree(int moves) {
////    return exploreMoves(moves, root);
////}
//
////double MoveTree::explore(int left, std::shared_ptr<MoveNode> node) {
////    if(left <= 0){
////        node->score = CheckerLogic::scoreBoard(node->curBoard);
////        return node->score;
////    }
////
////    std::vector<Move> moves = CheckerLogic::possibleMoves(node->curBoard);
////    double max = -INT32_MAX;
////    int multiply = 1;
////    if(node->curBoard.getPlayer() == 0){
////        multiply = -1;
////    }
////    Move best;
////    for(const Move& m : moves){
////        double score;
////        CheckerBoard b = CheckerLogic::doMove(m, node->curBoard);
////        std::shared_ptr<MoveNode> newChild =  std::make_shared<MoveNode>(b, left, 0, node, m);
////        node->addChild(newChild);
////        score = explore(left - 1, node->next.back());
////        if(multiply * score > max){
////            max = multiply * score;
////            best = m;
////        }
////    }
////    node->score = multiply * max;
////    node->bestMove = best;
////    return node->score;
////}
//
//std::pair<double, Move> MoveTree::exploreMoves(int left, CheckerBoard board) {
//    if(left <= 0){
//        return std::pair<double, Move>(CheckerLogic::scoreBoard(board), Move());
//    }
//    std::vector<Move> moves = CheckerLogic::possibleMoves(board);
//    int multiply = 1;
//    if(board.getPlayer() == 0){
//        multiply = -1;
//    }
//    Move best;
//    double max = -INT32_MAX;
//    for(const auto& m : moves){
//        std::pair<double, Move> tmp;
//        CheckerBoard tmpBoard = CheckerLogic::doTurn(m, board);
//        tmp = exploreMoves(left - 1, tmpBoard);
//        if(multiply * tmp.first > max){
//            max = multiply * tmp.first;
//            best = m;
//        }
//    }
//    return std::pair<double, Move>(max, best);
//}
//
//
////void MoveTree::addElem(std::shared_ptr<MoveNode> check) {
////    //int key = exploredMoves.computeHash(check->curBoard);
////
////
////}
////
////std::shared_ptr<MoveNode> MoveTree::getRoot() {
////    return root;
////}
//
////void MoveTree::updateRoot(const Move& lastMove) {
////    for(auto & node : root->next){
////        if(node->lastMove.equals(lastMove)){
////            root = node;
////            root->parent.reset();
////            break;
////        }
////    }
////}
////
////int MoveTree::getTreeSize() {
////    std::shared_ptr<MoveNode> cur = root;
////    while(cur->parent.lock() != nullptr){
////        cur = cur->parent.lock();
////    }
////    return getNodeSize(cur);
////}
////
////int MoveTree::getNodeSize(std::shared_ptr<MoveNode> node) {
////    int count = 1;
////    if(!node->next.empty()){
////        for(auto child : node->next){
////            count += getNodeSize(child);
////        }
////    }
////    return count;
////}
