//
// Created by daniella on 1/8/19.
//

#ifndef PROJ_2_ISEARCHER_H
#define PROJ_2_ISEARCHER_H

#include "ISearchable.h"
#include "State.h"
#include "MyPriorityQueue.h"

template <class S, class T>

class ISearcher {

public:
    virtual S search(ISearchable<T> *searchable) = 0;
};

#endif //PROJ_2_ISEARCHER_H
