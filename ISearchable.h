//
// Created by david on 1/9/19.
//

#ifndef PROJ_2_ISEARCHABLE_H
#define PROJ_2_ISEARCHABLE_H


#include "Searchable.h"
#include "State.h"

template <class T>

class ISearchable {
public:
    virtual State<T>* getInitialState() = 0;
    virtual bool isGoalState(State<T>* s) = 0;
    virtual list<State<T>*> getAllPossibleStates(State<T>* s) = 0;
};



#endif //PROJ_2_ISEARCHABLE_H
