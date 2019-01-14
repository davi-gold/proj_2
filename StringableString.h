//
// Created by daniella on 1/14/19.
//

#ifndef PROJ_2_STRINGABLESTRING_H
#define PROJ_2_STRINGABLESTRING_H

#include <vector>
#include "Stringable.h"

class StringableString: public Stringable {
public:

    string solution;

    StringableString(string str);

    virtual vector<string> convertToString();

    virtual void convertFromString(vector<string> fromString);
    string getString();

};


#endif //PROJ_2_STRINGABLESTRING_H
