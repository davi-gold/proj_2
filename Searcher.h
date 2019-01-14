//
// Created by daniella on 1/8/19.
//

#ifndef PROJ_2_SEARCHER_H
#define PROJ_2_SEARCHER_H

#include "ISearcher.h"
#include "State.h"
#include "MyPriorityQueue.h"

template<class P, class S, class T>

class Searcher : public ISearcher<P, S, T> {
protected:
    MyPriorityQueue<T> openList;
    int evalNodes;

public:
    Searcher() {};

    virtual S search(ISearchable<T> *searchable) = 0;

    // set the number of nodes evaluated
    void setEvaluatedNodes(int n) { this->evalNodes = n; }

    // return the number of nodes evaluated
    int getNumOfNodesEval() { return this->evalNodes; }

};


#endif //PROJ_2_SEARCHER_H
