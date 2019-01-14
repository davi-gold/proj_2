//
// Created by david on 1/13/19.
//

#include "DFS.h"
#include <stack>
#include <bits/unordered_set.h>

using namespace std;

template<class P, class S, class T>


S DFS<P, S, T>::search(ISearchable<T> *searchable) {

    stack<State<T> *> pStack;
    State<T> *s = searchable->getInitialState();
    s->setCameFrom(NULL);
    pStack.push(s);
    bool flag = true;

    while (!pStack.empty() && flag == true) {
        s = pStack.top();
        pStack.pop();
        this->evalNodes++;
        if (searchable->isGoalState(s->getState()))
            flag = false;
        if (flag) {
            if (s->getVisit() == false)
                s->setVisited(true);

            list<State<T> *> successors = searchable->getAllPossibleStates(s);
            typename list<State<T> *>::iterator iterator;

            for (iterator = successors.begin(); iterator != successors.end(); ++iterator) {
                State<T> *t = *iterator;
                t->setCameFrom(s);
                pStack.push(t);
            }
        }
    }
    vector<State<T> *> pVec = searchable->backTrace(s);
    if (pVec != NULL) {
        if (!pVec.empty())
            return searchable->getDirections(pVec);
        else return perror("path is empty!\n");
    } else return perror("path is NULL!\n");
}