//
// Created by david on 1/9/19.
//

#ifndef PROJ_2_BESTFIRSTSEARCH_H
#define PROJ_2_BESTFIRSTSEARCH_H


#include "Searcher.h"
#include <unordered_set>

template<class S, class T>

class BestFirstSearch : public Searcher <S, T>{
public:
     virtual S search(ISearchable<T> *searchable){
         State<T> *s = searchable->getInitialState();
         this->openList->push(s); // OPEN = [initial state] ::: a priority queue of states to be evaluated
         s->setCameFrom(NULL);
         searchable->getInitialState()->setVisited(true);
         unordered_set<State<T> *> *closed; // CLOSED = [] ::: a set of states already evaluated
         vector<State<T> *> pVec;
         bool flag = true;
         while (!(this->openList->getQueue()->empty()) && flag) {
             State<T> *n = this->openList->popAndGet(); // n <-- dequeue(OPEN) ::: Remove the best node from OPEN
             this->evalNodes++;
             closed->insert(n); // add(n,CLOSED) ::: so we won’t check n again

             if (searchable->isGoalState(n)) { // If n is the goal state
                 //*pVec = searchable->backTrace();
                 pVec = searchable->backTrace(n); // back traces through the parents, calling the delegated method, returns a list of states with n as a parent
                 flag = false;
             }
             if (flag) {
                 int evalNodes = this->getNumOfNodesEval();
                 evalNodes++;
                 this->setEvaluatedNodes(evalNodes);
                 list<State<T> *> successors = searchable->getAllPossibleStates(n); // Create n's successors
                 for (typename list<State<T>*>::iterator it = successors.begin(); it != successors.end(); ++it) {
                     State<T> *s = *it;
                     // generate relevant path
                     double thisPath = n->getCostPath() + s->getCost();

                     // if it is not in CLOSED and it is not in OPEN
                     //*!closed->find(s)
                     if (closed->find(s)!=closed->end() && !this->openList->find(s)) {
                         s->setCameFrom(n);
                         s->setCostPath(thisPath);
                         this->openList->push(s);
                     } else if (thisPath < s->getCostPath()) {
                         // Otherwise, if this new path is better than previous one
                         if (!this->openList->find(s))
                             this->openList->push(s);
                         else
                             this->openList->updatePrior(s, n);
                     }
                 }
             }
         }
         if (!pVec.empty())
             return searchable->getDirections(pVec);
         else
             //return perror("path is empty!\n");
             throw ("path is empty!\n");
     }
};


#endif //PROJ_2_BESTFIRSTSEARCH_H
