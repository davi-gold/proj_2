//
// Created by daniella on 1/11/19.
//

#ifndef PROJ_2_MATRIXSOLVER_H
#define PROJ_2_MATRIXSOLVER_H

#include "Solver.h"
#include "Searcher.h"

template <class S>
class MatrixSolver : public Solver<ISearchable<Point>*, S>{
    ISearcher <S, Point>* iSrch;
public:
    explicit MatrixSolver(ISearcher<S, Point>* s){
        this->iSrch = s;
    }

    S solve(ISearchable<Point>* prob)override{
        this->iSrch->search(prob);
    }

};

#endif //PROJ_2_MATRIXSOLVER_H
