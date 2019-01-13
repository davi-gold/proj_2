//
// Created by david on 1/13/19.
//

#ifndef PROJ_2_DFS_H
#define PROJ_2_DFS_H

#include <unordered_set>
#include <bits/unordered_set.h>
#include "BFS.h"

using namespace std;

template<class P, class S, class T>

#include "Searcher.h"

class DFS : public Searcher<P, S, T> {
    S search(ISearchable<T> *searchable);
};

#endif //PROJ_2_DFS_H
