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
protected:
    priority_queue<State<T>*> openList;
    int evaluatedNodes;

    virtual State<T>* popOpenList() {
        evaluatedNodes++;
        State<T>* temp = openList.top();
        openList.pop();
        return temp;
    };

public:
    Searcher() {
        openList = priority_queue<State<T>*>();
        evaluatedNodes = 0;
    };

    bool findInOpenList(State<T>* s) {
        priority_queue<State<T>*> openListCpy = this->openList;
        while (!openListCpy.empty()) {
            if (s->equals(std::move(const_cast<int &>(openListCpy.top())))) {
                return true;
            }
            openListCpy.pop();
        }
        return false;
    }

    void setEvaluatedNodes(int n) {
        this->evaluatedNodes = n;
    }

    virtual int OpenListSize() {
        return openList.size();
    };

    //purposely not virtual
    int getNumberOfNodesEvaluated() {
        return evaluatedNodes;
    };



    void updatePrior(State<T> *oldOne, State<T> *newOne) {
        vector<State<T>*> tVec;
        while (!this->openList.empty()) {
            State<T>* changedState = this->popFromthePq();
            tVec.push_back(changedState);
            if (oldOne->equals(newOne)){
                changedState->setCameFrom(newOne);
                changedState->setCostPath(newOne->getCostPath() + oldOne->getCost());
                break;
            }
        }
        for (int i = 0; i < tVec.size(); i++)
            this->openList.push(tVec[i]);
    }

    virtual S search(ISearchable<T> *searchable) = 0;
};


#endif //PROJ_2_SEARCHER_H
