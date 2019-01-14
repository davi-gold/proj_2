//
// Created by david on 1/9/19.
//

#ifndef PROJ_2_BESTFIRSTSEARCH_H
#define PROJ_2_BESTFIRSTSEARCH_H


#include "Searcher.h"

template<class S, class T>

class BestFirstSearch : public Searcher <S, T>{
public:
     virtual S search(ISearchable<T> *searchable);
};


#endif //PROJ_2_BESTFIRSTSEARCH_H
