//
// Created by daniella on 1/8/19.
//

#ifndef PROJ_2_SEARCHER_H
#define PROJ_2_SEARCHER_H

template <class P, class S>

class CacheManager {
public:
    S search(Searchable searchable) = 0;
    int getNumberOfNodesEvalutabled() = 0;

};

#endif //PROJ_2_SEARCHER_H
