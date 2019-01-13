//
// Created by daniella on 1/13/19.
//

#ifndef PROJ_2_STRINGABLE_H
#define PROJ_2_STRINGABLE_H

#include "string.h"
#include <iostream>

using namespace std;

template <class T>

class Stringable{
    string convertToString();

    T convertFromString(string fromString);
};

#endif //PROJ_2_STRINGABLE_H
