//
// Created by daniella on 1/13/19.
//

#ifndef PROJ_2_STRINGABLE_H
#define PROJ_2_STRINGABLE_H

#include "string.h"
#include <iostream>

using namespace std;


class Stringable{
    virtual vector<string> convertToString() = 0;

    virtual void convertFromString(vector<string> fromString) = 0;
};

#endif //PROJ_2_STRINGABLE_H
