//
// Created by david on 1/8/19.
//

#ifndef PROJ_2_SEARCHABLE_H
#define PROJ_2_SEARCHABLE_H

class Searchable {
public:
    virtual State getInitialState() = 0;
    virtual State getGoalState() = 0;
    virtual list<State> getAllPossibleStates(State s) = 0;
};

#endif //PROJ_2_SEARCHABLE_H
