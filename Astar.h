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
    S search(ISearchable<T> *searchable) {
        int g, f, h;
        unordered_set<State<T> *> *closed;
        State<T> *s = searchable->getInitialState();
        s->setCameFrom(NULL);
        this->openList->push(s); // Add the start node
        searchable->getInitialState()->setVisited(true);
        bool flag = true;
        while (!this->openList->getQueue().empty() && flag == true) {
            State<T> *n = this->openList->popAndGet();
            this->evalNodes++;
            closed->insert(n);

            list<State<T> *> successors = searchable->getAllPossibleStates(n); // Create n's successors
            for (typename list<State<T> *>::iterator it = successors.begin(); it != successors.end(); ++it) {
                State<T> *s = *it; // current node
                if (closed->find(s) != closed->end())
                    break;
                else {
                    if (!this->openList->find(s)) {
                        this->openList->push(s);
                        s->setCameFrom(n);
                        g = s->getCostPath();
                        // record the path
                        h = 0;
                        f = g + h;
                    } else {

                    }
                }
                // generate relevant path
                double thisPath = n->getCostPath() + s->getCost();


            }
        }


        State<T> *getLowestFcost(MyPriorityQueue<T> *q) {

        }
    };


#endif //PROJ_2_ASTAR_H
