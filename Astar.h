//
// Created by david on 1/14/19.
//

#ifndef PROJ_2_ASTAR_H
#define PROJ_2_ASTAR_H

#include "ISearchable.h"
#include "Searcher.h"

template<class S, class T>
class Astar : public Searcher<S, T> {
    S search(ISearchable<T> *searchable);
};


#endif //PROJ_2_ASTAR_H
