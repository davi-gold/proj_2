//
// Created by david on 1/9/19.
//

#include "BestFirstSearch.h"
template<class P, class S, class T>

S BestFirstSearch::search(ISearchable<T> searchable) {
   this->openList.push(searchable.getInitialState()); // OPEN = [initial state]

}
        addToOpenList(searchable. getInitialState ()); // inherited from Searcher
        HashSet<State> closed = new HashSet<State>();
        while (OpenListSize > 0) {
            State n = popOpenList(); // inherited from Searcher, removes the best state
            closed.Add(n);
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