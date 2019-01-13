//
// Created by daniella on 1/8/19.
//

#ifndef PROJ_2_ISEARCHER_H
#define PROJ_2_ISEARCHER_H

#include "Searchable.h"
#include "State.h"

template <class P, class S, class T>

class ISearcher {
protected:
    virtual State<T> popOpenList();

public:
    virtual int OpenListSize() = 0;
    virtual int getNumberOfNodesEvaluated() = 0;
    virtual S search(Searchable<T> *searchable) = 0;
};

#endif //PROJ_2_ISEARCHER_H
