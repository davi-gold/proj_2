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
    priority_queue<State<T>> openList;
    int evaluatedNodes;

    virtual State<T> popOpenList() {
        evaluatedNodes++;
        return openList.top();
    };

public:
    Searcher() {
        openList = new priority_queue<State<T>>();
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


    vector<State<T> *> backTrace(State<T> *goalState) {
        vector<State<T> *> path;
        path.push_back(goalState);

        while (goalState->getCamefrom() != NULL) {
            State<T> *parent = goalState->getCamefrom();
            path.push_back(parent);
            goalState = parent;
        }

        reverse(path.begin(), path.end());
        return path;
    }


    void updatePrior(State<T> *state) {
        vector<State<T>> tVec;
        while (!this->openList.empty()) {
            State<T> changedState = this->popFromthePq();
            if (changedState.equals(state))
                tVec.push_back(state);
            else
                tVec.push_back(changedState);
        }
        for (int i = 0; i < tVec.size(); i++)
            this->openList.push(tVec[i]);
    }

    virtual S search(Searchable<T> searchable);
};


#endif //PROJ_2_SEARCHER_H
