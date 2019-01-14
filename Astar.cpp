//
// Created by david on 1/14/19.
//

#include "Astar.h"

using namespace std;

template<class S, class T>

S Astar<S, T>::search(ISearchable<T> *searchable) {
    this->openList.push(searchable->getInitialState()); // Add the start node
    bool flag = true;
    while (!this->openList.getQueue().empty() && flag == true) {
        State<T> *n = this->openList.popAndGet();
        this->evalNodes++;

    }


}