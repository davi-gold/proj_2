//
// Created by daniella on 1/8/19.
//

#ifndef PROJ_2_ISEARCHER_H
#define PROJ_2_ISEARCHER_H

#include "ISearchable.h"
#include "State.h"

template <class S, class T>

class ISearcher {
protected:
    virtual State<T>* popOpenList() = 0;

public:
    virtual int OpenListSize() = 0;
    virtual int getNumberOfNodesEvaluated() = 0;
    virtual S search(ISearchable<T> *searchable) = 0;
};

#endif //PROJ_2_ISEARCHER_H
