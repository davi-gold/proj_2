//
// Created by david on 1/8/19.
//

#ifndef PROJ_2_SEARCHABLE_H
#define PROJ_2_SEARCHABLE_H

#include <list>
#include "State.h"

template <class T>

class Searchable {
public:
    virtual State<T> getInitialState() = 0;
    virtual State<T> getGoalState() = 0;
    virtual list<State<T>> getAllPossibleStates(State<T> s) = 0;
};

#endif //PROJ_2_SEARCHABLE_H
