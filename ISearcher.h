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
    virtual int OpenListSize();

    virtual int getNumberOfNodesEvaluated();

    virtual S search(ISearcher<P, S, T> searchable);
};

#endif //PROJ_2_ISEARCHER_H
