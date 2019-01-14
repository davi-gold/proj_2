//
// Created by david on 1/9/19.
//

#ifndef PROJ_2_ISEARCHABLE_H
#define PROJ_2_ISEARCHABLE_H


#include <vector>
#include <list>
#include "State.h"

template <class T>

class ISearchable {
public:
    virtual State<T>* getInitialState() = 0;
    virtual bool isGoalState(State<T>* s) = 0;
    virtual string getDirections(vector<State<T>*> p) = 0;
    virtual list<State<T>*> getAllPossibleStates(State<T>* s) = 0;
    vector<State<T> *> backTrace(State<T> *goalState) {
        vector<State<T> *> path;
        path.push_back(goalState);

        while (goalState->getCamefrom() != NULL) {
            State<T> *parent = goalState->getCamefrom();
            path.push_back(parent);
            goalState = parent;
        }

        reverse(path.begin(), path.end());
        return path;
    }
};



#endif //PROJ_2_ISEARCHABLE_H
