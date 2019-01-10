//
// Created by daniella on 1/10/19.
//

#include "MatrixSearchable.h"

MatrixSearchable::MatrixSearchable(int size) {
    mSize = size;
}

//sets myMatrix
void MatrixSearchable::setMatrix(vector<string> matList) {
    unsigned long int i = 0;
    unsigned long int j = 0;
    string row;
    for (i; i < mSize; i++) {
        row = matList.at(i);
        string strVal;
        int val;
        int rIndex = 0;
        for (j; j < mSize; j++) {
            j = row.find(',');
            strVal = row.substr(rIndex, j);
            rIndex = j + 1;
            val = atoi(strVal.c_str());
            State<pair<int, int>> curState = State<pair<int, int>>(pair<int, int>(i, j), val);
            //curstate should be in index i,j beacuse for each row we will do pushback j times
            myMatrix.at(i).push_back(curState);
        }
    }
}

void MatrixSearchable::setInitialState(string inI, string inJ) {
    int i = atoi(inI.c_str());
    int j = atoi(inJ.c_str());

    initialState = myMatrix.at(i).at(j);
}


void MatrixSearchable::setGoalState(string inI, string inJ) {
    int i = atoi(inI.c_str());
    int j = atoi(inJ.c_str());

    goalState = myMatrix.at(i).at(j);
}