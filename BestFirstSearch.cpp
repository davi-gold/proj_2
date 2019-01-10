//
// Created by david on 1/9/19.
//

#include "BestFirstSearch.h"

template<class P, class S, class T>

S BestFirstSearch::search(ISearchable<T> searchable) {
    this->openList.push(
            searchable.getInitialState()); // OPEN = [initial state] ::: a priority queue of states to be evaluated
    std::unordered_set<State<T>> *closed; // CLOSED = [] ::: a set of states already evaluated
    while (!openList.empty()) {
        State<T> n = popOpenList(); // n <-- dequeue(OPEN) ::: Remove the best node from OPEN
        closed->insert(n); // add(n,CLOSED) ::: so we won’t check n again
        if (searchable.isGoalState(n)) // If n is the goal state
            return backTrace(); // // private method, back traces through the parents, calling the delegated method, returns a list of states with n as a parent
        list<State<T>> successors = searchable.getAllPossibleStates(n); // Create n's successors
        for (State<T> s : successors) {
            double path = n.getCost() + s.getCost();
            if (!closed.find(s) && !this->findInOpenList(s)){
                s.setCameFrom(n);
                s.setPath(path);
                this->openList.push(s);
            } else if {
                // Otherwise, if this new path is better than previous one
                (path < s.getCost())
                {
                    if (!this->findInOpenList(s))
                        this->openList.push(s);
                    else
                        updatePrior(s);
                }
            }
        }
    }
}