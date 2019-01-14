//
// Created by david on 1/13/19.
//

#ifndef PROJ_2_BFS_H
#define PROJ_2_BFS_H

#include <bits/unordered_set.h>
#include "Searcher.h"

template<class S, class T>

class BFS : public Searcher <S, T> {
    S search(ISearchable<T> *searchable) override;
};

#endif //PROJ_2_BFS_H
