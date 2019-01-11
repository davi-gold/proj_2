//
// Created by daniella on 1/11/19.
//

#ifndef PROJ_2_MATRIXSOLVER_H
#define PROJ_2_MATRIXSOLVER_H

#include "Solver.h"
#include "Searcher.h"

template <class P, class S, class T>
class MatrixSolver : public Solver<P, S>{
    ISearcher <P, S, T> iSrch;
    ISearchable<T> iSrchable;
public:
    MatrixSolver(ISearcher<P, S, T> s, ISearchable<T> is){
        this->iSrch = s;
        this->iSrchable = is;
    }

    const S& solve(P& p){
        this->iSrch.search(this->p);
    }

};

#endif //PROJ_2_MATRIXSOLVER_H
