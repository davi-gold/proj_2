//
// Created by david on 1/7/19.
//

#include "StringReverser.h"

StringReverser::StringReverser(){}

string StringReverser::solve(string problem) {
    int len = problem.length();
    for (int i = 0; i < len / 2; i++)
        swap(problem[i], problem[len - i - 1]);
    problem.push_back('\r');
//    problem.push_back('\n');
    return problem;
}

