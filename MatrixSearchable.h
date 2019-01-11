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
        for(int k = 0;k<mSize;k++){
            vector<State<Point>*> cur_vec;
            myMatrix.push_back(cur_vec);
        }
        string row;
        for (unsigned long int i = 0; i < mSize; i++) {
            unsigned long int rowCounter = 0;
            unsigned long int comma = 0;
            row = matList.at(i);
            string strVal;
            double val;
            for (unsigned long int j = 0; j < mSize; j++) {
                if(rowCounter == mSize-1){
                    strVal = row;
                }else{
                    comma = row.find(',');
                    strVal = row.substr(0, comma);
                    row = row.substr(comma+1, row.size());
                    rowCounter++;
                }
                val = atoi(strVal.c_str());
                //index i, j-1 becuase j will run from 1 and not from zero(j is according to commas)
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
        int i = stoi(iStr.c_str());
        int j = stoi(jStr.c_str());

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
            //up
            possibleStates.push_back(myMatrix.at(i-1).at(0));
            //down
            possibleStates.push_back(myMatrix.at(i+1).at(0));
            //right
            possibleStates.push_back(myMatrix.at(i).at(1));
        }
        else if(i == mSize-1){
            if(j  == mSize-1){
                //left
                possibleStates.push_back(myMatrix.at(mSize-1).at(j-1));
                //up
                possibleStates.push_back(myMatrix.at(i-1).at(mSize-1));
            }
                //j<mSize-1
            else{
                //left
                possibleStates.push_back(myMatrix.at(mSize-1).at(j-1));
                //right
                possibleStates.push_back(myMatrix.at(mSize-1).at(j+1));
                //up
                possibleStates.push_back(myMatrix.at(i-1).at(j));
            }
        }
            //i!=mSize-1 beacuse we already checked
        else if(j == mSize-1){
            //down
            possibleStates.push_back(myMatrix.at(i+1).at(mSize-1));
            //up
            possibleStates.push_back(myMatrix.at(i-1).at(mSize-1));
            //right
            possibleStates.push_back(myMatrix.at(i).at(j-1));
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
