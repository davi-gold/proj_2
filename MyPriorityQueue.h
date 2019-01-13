//
// Created by daniella on 1/12/19.
//

#ifndef PROJ_2_MYPRIORITYQUEUE_H
#define PROJ_2_MYPRIORITYQUEUE_H


#include <queue>
template<class T,class Container = std::vector<T>,class Compare = std::less<typename Container::value_type>>
class MyPriorityQueue : public std::priority_queue<T, Container, Compare>{
public:
    typedef typename
    std::priority_queue<
            T,
            Container,
            Compare>::container_type::const_iterator const_iterator;

    const_iterator find(const T&val) const
    {
        auto first = this->c.cbegin();
        auto last = this->c.cend();
        while (first!=last) {
            if (*first==val) return first;
            ++first;
        }
        return last;
    }
};



#endif //PROJ_2_MYPRIORITYQUEUE_H
