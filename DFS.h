//
// Created by daniella on 1/9/19.
//

#ifndef PROJ_2_DFS_H
#define PROJ_2_DFS_H


#include "Searcher.h"
#include <stack>
template <class P, class S, class T>
class DFS : public Searcher<P, S, T>{
public:
    DFS(){};
    S search (ISearchable<T> searchable){
        stack<State<T>> s;
        s.push(searchable.getInitialState());
        this->openList.emplace(searchable.getInitialState());

        while(!s.isEmpty()) {
            State<T> currentState = s.top();
            if(searchable.isGoalState(currentState)) {
                return currentState.backtrace();
            }
            list<State<T>> nextNeighbors =searchable.getAllPossibleStates(currentState);

            for(State<T> child: nextNeighbors) {
                if(!this->openList.find(child)) {
                    s.add(child);
                    this->openList.emplace(child);
                }
            }
        }
        return nullptr;
    }

};


#endif //PROJ_2_DFS_H
