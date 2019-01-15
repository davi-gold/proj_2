//
// Created by daniella on 1/14/19.
//

#include "StringableString.h"

StringableString:: StringableString(string str){
    solution = str;
}

StringableString:: StringableString(){
    solution = {};
}

vector<string> StringableString:: convertToString(){

    vector<string> vecSolution;
    vecSolution.emplace_back(solution);
    return vecSolution;
}

void StringableString::  convertFromString(vector<string> fromString){
    solution = fromString.front();
}

string StringableString:: getString(){
    return solution;
}