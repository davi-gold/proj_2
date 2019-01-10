//
// Created by daniella on 1/10/19.
//

#ifndef PROJ_2_MATRIXSEARCHABLE_H
#define PROJ_2_MATRIXSEARCHABLE_H


#include "Searchable.h"
#include <vector>
//#include <bits/valarray_after.h>

using Point =std::pair<int,int>;
class MatrixSearchable : public Searchable<Point>{
    int mSize;
    vector<vector<State<Point>*>> myMatrix;
    State<Point>* initialState;
    State<Point>* goalState;
public:
    MatrixSearchable(int size) {
        mSize = size;
    }

//sets myMatrix
    void setMatrix(vector<string> matList) {
        unsigned long int i = 0;
        unsigned long int j = 0;
        string row;
        for (i; i < mSize; i++) {
            row = matList.at(i);
            string strVal;
            double val;
            int rIndex = 0;
            for (j; j < mSize; j++) {
                j = row.find(',');
                strVal = row.substr(rIndex, j);
                rIndex = j + 1;
                val = atoi(strVal.c_str());
                State<Point>* curState = new State<Point>(Point(i, j), val);
                //curstate should be in index i,j beacuse for each row we will do pushback j times
                myMatrix.at(i).push_back(curState);
            }
        }
    }

    void setInitialState(string index) {
        unsigned long int comma = index.find(',');
        string iStr = index.substr(0, comma);
        string jStr = index.substr(comma + 1, index.size());
        int i = atoi(iStr.c_str());
        int j = atoi(jStr.c_str());

        initialState = myMatrix.at(i).at(j);
    }


    void setGoalState(string index) {
        unsigned long int comma = index.find(',');
        string iStr = index.substr(0, comma);
        string jStr = index.substr(comma + 1, index.size());
        int i = atoi(iStr.c_str());
        int j = atoi(jStr.c_str());

        goalState = myMatrix.at(i).at(j);
    }

    State<Point>* getInitialState(){
        return initialState;
    }
    bool isGoalState(State<Point>* s){
        return s == goalState;
    }
    list<State<Point>*> getAllPossibleStates(State<Point>* s){
        list<State<Point>*> possibleStates;
        int i = s->getState().first;
        int j = s->getState().second;

        if(i == 0){
            if(j  == 0){
                possibleStates.push_back(myMatrix.at(0).at(1));
                possibleStates.push_back(myMatrix.at(1).at(0));
            }
                //j>0
            else{
                //left
                possibleStates.push_back(myMatrix.at(0).at(j-1));
                //right
                possibleStates.push_back(myMatrix.at(0).at(j+1));
                //down
                possibleStates.push_back(myMatrix.at(1).at(j));
            }
        }
            //i!=0 beacuse we already checked
        else if(j == 0){
            //down
            possibleStates.push_back(myMatrix.at(i-1).at(0));
            //up
            possibleStates.push_back(myMatrix.at(i+1).at(0));
            //right
            possibleStates.push_back(myMatrix.at(i).at(1));
        }
        else{
            //left
            possibleStates.push_back(myMatrix.at(i).at(j-1));
            //right
            possibleStates.push_back(myMatrix.at(i).at(j+1));
            //up
            possibleStates.push_back(myMatrix.at(i-1).at(j));
            //down
            possibleStates.push_back(myMatrix.at(i+1).at(j));
        }

        return possibleStates;
    }


};


#endif //PROJ_2_MATRIXSEARCHABLE_H
