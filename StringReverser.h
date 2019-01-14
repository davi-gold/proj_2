//
// Created by david on 1/7/19.
//

#ifndef PROJ_2_STRINGREVERSER_H
#define PROJ_2_STRINGREVERSER_H

#include "Solver.h"
#include <string>

using namespace std;

class StringReverser : public Solver<string, string> {
public:
    // empty constructor
    StringReverser();
    string solve(string problem) override;
};


#endif //PROJ_2_STRINGREVERSER_H
