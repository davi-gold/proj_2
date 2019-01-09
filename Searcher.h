//
// Created by daniella on 1/8/19.
//

#ifndef PROJ_2_SEARCHER_H
#define PROJ_2_SEARCHER_H

#include <queue>
#include "ISearcher.h"
#include "State.h"

template<class P, class S, class T>

class Searcher : public ISearcher<P, S, T> {

    priority_queue<State<T>> openList;
    int evaluatedNodes;
protected:
    virtual State<T> popOpenList(){
        evaluatedNodes++;
        return openList.top();
    };

public:
    Searcher() {
        openList = new priority_queue<State<T>>();
        evaluatedNodes = 0;
    };

    virtual int OpenListSize(){
        return openList.size();
    };

    //purposely not virtual
    int getNumberOfNodesEvaluated(){
        return evaluatedNodes;
    };

    virtual S search(ISearcher<P, S, T> searchable);
};


#endif //PROJ_2_SEARCHER_H
