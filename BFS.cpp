//
// Created by david on 1/13/19.
//
#include <unordered_set>
#include "BFS.h"

using namespace std;

template<class S, class T>


S BFS<S, T>::search(ISearchable<T> *searchable) {
    vector<State<T> *> pVec;
    unordered_set<State<T> *> *closed;
    State<T> *s = searchable->getInitialState();
    s->setCameFrom(NULL);
    this->openList.push(s);
    searchable->getInitialState()->setVisited(true);
    bool flag = true;

    while (!this->openList.getQueue().empty() && flag == true) { // while openList is not empty
        State<T> *n = this->openList.popAndGet();
        this->evalNodes++;
        if (searchable->isGoalState(n)) {
            closed->insert(n);
            pVec = searchable->backTrace(n);
            flag = false;
        }
        if (flag) {
            this->evalNodes++;
            list<State<T> *> successors = searchable->getAllPossibleStates(n); // Create n's successors
            for (typename list<State<T>>::iterator it = successors.begin(); it != successors.end(); ++it) {
                State<T> *s = *it;
                s->setCameFrom(n);
                this->openList.push(s);
            }
        }
    }
    if (pVec != NULL) {
        if (!pVec.empty())
            return searchable->getDirections(pVec);
        else return perror("path is empty!\n");
    } else return perror("path is NULL!\n");
}
