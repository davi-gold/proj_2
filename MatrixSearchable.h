//
// Created by daniella on 1/10/19.
//

#ifndef PROJ_2_MATRIXSEARCHABLE_H
#define PROJ_2_MATRIXSEARCHABLE_H


#include "Searchable.h"
#include <vector>
#include <bits/valarray_after.h>


class MatrixSearchable : public Searchable<pair<int, int>>{
    int mSize;
    vector<vector<State<pair<int, int>>>> myMatrix;
    State<pair<int, int>> initialState;
    State<pair<int, int>> goalState;
public:
    MatrixSearchable(int size);
    virtual State<pair<int, int>> getInitialState();
    virtual bool isGoalState(State<pair<int, int>> s);
    virtual list<State<pair<int, int>>> getAllPossibleStates(State<pair<int, int>> s);
    void setMatrix(vector<string> matList);
    void setInitialState(string index);
    void setGoalState(string index);

};


#endif //PROJ_2_MATRIXSEARCHABLE_H
