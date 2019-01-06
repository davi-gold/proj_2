//
// Created by david on 1/3/19.
//

#ifndef PROJ_2_SOLVER_H
#define PROJ_2_SOLVER_H

#include "Solution.h"
#include "Problem.h"

template <class P, class S>

class Solver {
public:
virtual S solve(P p) = 0;
};


#endif //PROJ_2_SOLVER_H
