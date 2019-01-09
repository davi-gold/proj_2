//
// Created by david on 1/9/19.
//

#include "BestFirstSearch.h"
template<class P, class S, class T>

S BestFirstSearch::search(ISearchable<T> searchable) {
    this->openList.push(searchable.getInitialState()); // OPEN = [initial state] ::: a priority queue of states to be evaluated
    std::unordered_set<State<T>> *closed; // CLOSED = [] ::: a set of states already evaluated
    while (!openList.empty()){
    State<T> n = popOpenList(); // n <-- dequeue(OPEN) ::: Remove the best node from OPEN
    closed->insert(n); // add(n,CLOSED) ::: so we won’t check n again
    if(n.Equals()) // If n is the goal state
    }
} // while OPEN is not empty


}



            if (n.Equals(searchable. getIGoallState ()))
                return backTrace(); // private method, back traces through the parents
// calling the delegated method, returns a list of states with n as a parent
            List<State> succerssors = searchable. getAllPossibleStates(n);
            foreach (State s in succerssors)
            {
                if (!closed.Contains(s) && !openContaines(s))
                {
// s.setCameFrom(n); // already done by getSuccessors
                    addToOpenList(s);
                }
                else
}