//
// Created by david on 1/9/19.
//

#ifndef PROJ_2_BESTFIRSTSEARCH_H
#define PROJ_2_BESTFIRSTSEARCH_H


#include "Searcher.h"

template<class P, class S, class T>

class BestFirstSearch : public Searcher <P, S, T>{
public:
     S search(ISearcher<P, S, T> searchable) override;
};


#endif //PROJ_2_BESTFIRSTSEARCH_H
