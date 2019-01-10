//
// Created by david on 1/8/19.
//

#ifndef PROJ_2_STATE_H
#define PROJ_2_STATE_H

#include <string>

using namespace std;

template <class T>

class State {
    T state; // the state represented by a string
    double cost; // cost to reach this state (set by a setter)
    State<T> cameFrom; // the state we came from to this state (setter)

public:
    // CTOR
    State(T st, double c){
        state = st;
        cost = c;
    }
    bool equals(State<T> other){
        return state == other.getState();
    }

    double getCost(){
        return cost;
    }

    State<T> getCameFrom(){
        return cameFrom;
    }

    T getState(){
        return state;
    }

    void setCameFrom(State<T> cFrom){
        cameFrom = cFrom;
    }
};

#endif //PROJ_2_STATE_H