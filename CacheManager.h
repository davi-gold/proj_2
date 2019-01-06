//
// Created by david on 1/3/19.
//

#ifndef PROJ_2_CACHEMANAGER_H
#define PROJ_2_CACHEMANAGER_H


#include "Problem.h"
#include "Solution.h"

template <class P, class S>

class CacheManager {
public:
    virtual bool isSaved(P p) = 0;
    virtual S getSolution(P p) = 0;
    virtual void saveSolution(P p, S s) = 0;
};


#endif //PROJ_2_CACHEMANAGER_H
