//
// Created by david on 1/14/19.
//

#ifndef PROJ_2_MYPRIORITYQUEUE_H
#define PROJ_2_MYPRIORITYQUEUE_H

#include <queue>
#include "State.h"
#include "Compare.h"

using namespace std;

template<class T>

class MyPriorityQueue {
    class Compare {
    public:
        bool operator()(State<T> *one, State<T> *two) {
            return (one->getCostPath() > two->getCostPath());
        }
    };

    // data members
    priority_queue<State<T> *, vector<State<T> *>, Compare> *queue;

    // CTOR and functions
public:
    // empty constructor
    MyPriorityQueue() {
//        this->queue = new priority_queue<State<T> *>();
    }


    // pop func
    State<T> *popAndGet() {
        State<T> *tmp = this->queue->top();
        this->queue->pop();
        return tmp;
    }

    // find in queue func
    bool find(State<T> *state) {
        priority_queue<State<T> *, vector<State<T> *>, Compare> list = *this->queue;
        while (!list.empty()) {
           // if (state->equals(std::move(const_cast<int &>(list.top()))))
           State<T> *curState = list.top();
           if(state->equals(curState))
                return true;
           list.pop();
        }
        return false;
    }


    // return the size
    int size() {
        return this->queue->size();
    }


    // push function
    void push(State<T> *state) {
        this->queue->push(state);
    }

    State<T> *top() {
        this->queue->top();
    }

    // update the priority
    void updatePrior(State<T> *oldOne, State<T> *newOne) {
        vector<State<T> *> tVec;
        while (!this->queue->empty()) {
            State<T> *changedState = this->queue->top();
            this->queue->pop();
            tVec.push_back(changedState);
            if (oldOne->equals(newOne)) {
                changedState->setCameFrom(newOne);
                changedState->setCostPath(newOne->getCostPath() + oldOne->getCost());
                break;
            }
        }
        for (int i = 0; i < tVec.size(); i++)
            this->queue->push(tVec[i]);
    }

    priority_queue<State<T> *, vector<State<T> *>, Compare> *getQueue() {
        return this->queue;
    }
};

#endif //PROJ_2_MYPRIORITYQUEUE_H
