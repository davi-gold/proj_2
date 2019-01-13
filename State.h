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
    State<T>* cameFrom; // the state we came from to this state (setter)
    double path;
    double costPath;
    bool visited = false;

public:
    // CTOR
    State(T st, double c){
        state = st;
        cost = c;
        cameFrom = nullptr;
    }

    bool getVisit() {
        return this->visited;
    }
    T getState(){
        return state;
    }

    void setCameFrom(State<T>* cFrom){
        cameFrom = cFrom;
    }
    int getCost(){
        this->cost;
    }

    void setPath(double p){
        this->path = p;
    }

    void setVisited(bool boolean){
        this->visited = boolean;
    }

    bool equals(State<T> other){
        return this->costPath == other.costPath;
    }

    bool greaterThan (State<T>* other){
        return this->costPath > other->costPath;
    }

    bool lessThan (State<T>* other){
        return this->costPath < other->costPath;
    }

    double getCostPath(){
        return this->costPath;
    }

    void setCostPath(double p){
        this->costPath = p;
    }

};

#endif //PROJ_2_STATE_H