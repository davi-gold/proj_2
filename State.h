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
    State(T st){
        state = st;
    }
    bool equals(State<T> other){
        return state == other.getState();
    }
    T getState(){
        return state;
    }
};

#endif //PROJ_2_STATE_H