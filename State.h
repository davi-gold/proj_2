//
// Created by david on 1/8/19.
//

#ifndef PROJ_2_STATE_H
#define PROJ_2_STATE_H

#include <string>

using namespace std;

class State {
    string state; // the state represented by a string
    double cost; // cost to reach this state (set by a setter)
    State cameFrom; // the state we came from to this state (setter)

public:
    State(string state); // CTOR
    bool Equals(object obj);

#endif //PROJ_2_STATE_H