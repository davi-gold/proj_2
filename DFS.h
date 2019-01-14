//
// Created by david on 1/13/19.
//

#ifndef PROJ_2_DFS_H
#define PROJ_2_DFS_H

#include <unordered_set>
#include "BFS.h"

using namespace std;

template<class S, class T>

#include "Searcher.h"

class DFS : public Searcher<S, T> {
    S search(ISearchable<T> *searchable);
};

#endif //PROJ_2_DFS_H