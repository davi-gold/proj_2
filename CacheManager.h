//
// Created by david on 1/3/19.
//

#ifndef PROJ_2_CACHEMANAGER_H
#define PROJ_2_CACHEMANAGER_H


#include "Problem.h"
#include "Solution.h"

class CacheManager {
    virtual bool isSaved(Problem p) = 0;
    virtual Solution getSolution(Problem p) = 0;
    virtual bool saveSolution(Solution s) = 0;
};


#endif //PROJ_2_CACHEMANAGER_H
