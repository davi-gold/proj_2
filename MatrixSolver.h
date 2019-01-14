//
// Created by daniella on 1/11/19.
//

#ifndef PROJ_2_MATRIXSOLVER_H
#define PROJ_2_MATRIXSOLVER_H

#include "Solver.h"
#include "Searcher.h"

template <class S, class T>
class MatrixSolver : public Solver<ISearchable<T>, S>{
    ISearcher <S, T> iSrch;
    ISearchable<T> iSrchable;
public:
    MatrixSolver(ISearcher<S, T> s, ISearchable<T> is){
        this->iSrch = s;
        this->iSrchable = is;
    }

    const S& solve(ISearchable<T>& p){
        this->iSrch.search(this->p);
    }

};

#endif //PROJ_2_MATRIXSOLVER_H
