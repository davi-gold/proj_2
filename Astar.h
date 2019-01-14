//
// Created by david on 1/14/19.
//

#ifndef PROJ_2_ASTAR_H
#define PROJ_2_ASTAR_H

#include "ISearchable.h"
#include "Searcher.h"

template<class S, class T>
class Astar : public Searcher<S, T> {
    S search(ISearchable<T> *searchable) {
        unordered_set < State<T> * > *closed;
        State<T> *s = searchable->getInitialState();
        s->setCameFrom(NULL);
        this->openList->push(s); // Add the start node
        searchable->getInitialState()->setVisited(true);
        bool flag = true;
        while (!this->openList->getQueue().empty() && flag == true) {
            State<T> *n = this->openList->popAndGet();
            this->evalNodes++;


        }
    }
};


#endif //PROJ_2_ASTAR_H
