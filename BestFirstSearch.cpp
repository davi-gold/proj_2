//
// Created by david on 1/9/19.
//

#include <unordered_set>
#include <bits/unordered_set.h>
#include "BestFirstSearch.h"

using namespace std;

template<class P, class S, class T>

S BestFirstSearch<P, S, T>::search(ISearchable<T> *searchable) {
    this->openList.push(
            searchable->getInitialState()); // OPEN = [initial state] ::: a priority queue of states to be evaluated
    searchable->getInitialState()->setVisited(true);
    unordered_set<State<T> *> *closed; // CLOSED = [] ::: a set of states already evaluated
    vector<State<T> *> pVec;
    while (!this->openList.empty()) {
        State<T> *n = this->popOpenList(); // n <-- dequeue(OPEN) ::: Remove the best node from OPEN
        closed->insert(n); // add(n,CLOSED) ::: so we won’t check n again

        if (searchable->isGoalState(n)) { // If n is the goal state
            pVec = searchable->backTrace(); // back traces through the parents, calling the delegated method, returns a list of states with n as a parent
            break;
        }

        this->evaluatedNodes++;
        list<State<T> *> successors = searchable->getAllPossibleStates(n); // Create n's successors
        for (typename list<State<T>>::iterator it = successors.begin(); it != successors.end(); ++it) {
            State<T> *s = *it;
            // generate relevant path
            double thisPath = n->getCostPath() + s->getCost();
            // if it is not in CLOSED and it is not in OPEN
            if (!closed->find(s) && !this->findInOpenList(s)) {
                s->setCameFrom(n);
                s->setCostPath(thisPath);
                this->openList.push(s);
            } else if (thisPath < s->getCostPath()) {
                // Otherwise, if this new path is better than previous one
                if (!this->findInOpenList(s))
                    this->openList.push(s);
                else
                    this->updatePrior(s, n);
            }
        }
    }
    if (pVec != NULL)
        return searchable->getDirections(pVec);
    else
        return perror("The path vector is NULL!\n");
}