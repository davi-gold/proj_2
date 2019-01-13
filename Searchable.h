//
// Created by david on 1/8/19.
//

#ifndef PROJ_2_SEARCHABLE_H
#define PROJ_2_SEARCHABLE_H

#include <list>
#include "State.h"
#include "ISearchable.h"

template <class T>

class Searchable : public ISearchable<T> {
public:
    virtual State<T>* getInitialState();
    virtual bool isGoalState(State<T>* s);
    virtual list<State<T>*> getAllPossibleStates(State<T>* s);
    virtual vector<string> getDirections(vector<State<T>*> p);

};

#endif //PROJ_2_SEARCHABLE_H
