#pragma once
#include "List.hpp"

template <typename T>
class Deque : private List<T>
{

public:
    Deque();
    ~Deque();

    
    void push_front(const T &knot);
    void pop_back();
    void pop_front();
}


