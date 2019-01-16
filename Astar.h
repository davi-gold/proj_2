//
// Created by david on 1/14/19.
//

#ifndef PROJ_2_ASTAR_H
#define PROJ_2_ASTAR_H

#include <unordered_set>
#include "ISearchable.h"
#include "Searcher.h"

template<class S, class T>

class Astar : public Searcher<S, T> {
    vector<State<T> *> openListVec;


    S* search(ISearchable<T> *searchable) {
        this->evalNodes = 0;
        vector<State<T> *> closeList;
        State<T> *initialState = searchable->getInitialState();
        State<T> *goalState = searchable->getGoal();

        this->openListVec.push_back(initialState);
        while (!this->openListVec.empty()) {
            State<T> *thisState = this->lowest(goalState);
            thisState->setVisited(true);
            closeList.push_back(thisState);
            this->evalNodes++;

            if (goalState->getState() == thisState->getState())
                break;

            searchable->updateVisitOnOff(false);
            list<State<T> *> successors = searchable->getAllPossibleStates(thisState);
            searchable->updateVisitOnOff(true);
            while (!successors.empty()) {
                State<T> *tState = successors.back();
                successors.pop_back();
                if (tState->getVisit())
                    continue;

                double newPath = thisState->getCostPath() + tState->getCost();
                if (find(this->openListVec.begin(), this->openListVec.end(), tState) != this->openListVec.end()) {
                    if (tState->getCostPath() < newPath)
                        continue;
                } else if (find(closeList.begin(), closeList.end(), tState) != closeList.end()) {
                    if (tState->getCostPath() < newPath)
                        continue;

                    vector<State<T> *> toOpen;
                    typename vector<State<T> *>::iterator it;

                    for (it = closeList.begin(); it != closeList.end(); ++it) {
                        State<T> *n = closeList.back();
                        closeList.pop_back();
                        toOpen.push_back(n);

                        if (n == tState)
                            this->openListVec.push_back(n);
                    }
                } else
                    this->openListVec.push_back(tState);

                tState->setCostPath(newPath);
                tState->setCameFrom(thisState);
            }
        }
        vector<State<T> *> pVec = searchable->backTrace(searchable->getGoal());
        if (!pVec.empty())
            return searchable->getDirections(pVec);
        else throw ("path is empty!\n");
    }


    State<T> *lowest(State<T> *g) {
        vector<State<T> *> temporaryStVec;
        State<T> *lowValst = this->openListVec.back();
        openListVec.pop_back();

        double a = std::abs(lowValst->getState().first - g->getState().first);
        double b = std::abs(lowValst->getState().second - g->getState().second);
        double heu = a + b; // heuristic
        double one = lowValst->getCostPath() + heu;

        while (!this->openListVec.empty()) {
            State<T> *st = openListVec.back();
            openListVec.pop_back();

            double a = std::abs(st->getState().first - g->getState().first);
            double b = std::abs(st->getState().second - g->getState().second);
            double heu = a + b; // heuristic
            double two = st->getCostPath() + heu;

            if (one > two) {
                one = two;
                temporaryStVec.push_back(lowValst);
                lowValst = st;
                continue;
            }
            temporaryStVec.push_back(st);
        }
        for (int i = 0; i < temporaryStVec.size(); i++)
            this->openListVec.push_back(temporaryStVec[i]);
        return lowValst;
    }
};


#endif //PROJ_2_ASTAR_H
