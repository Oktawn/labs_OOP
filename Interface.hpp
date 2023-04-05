#pragma once
#include "Stack.hpp"
#include "Deque.hpp"

class Calculator
{
    Stack<int> store, temp;
public:
    double result(std::string equation)
    {
        for (auto i : equation)
        {
            if (!isblank(i))
                if (isdigit(i))
                    store.push(i - '0');
                else
                {
                    switch (i)
                    {
                    case '+':
                        temp.push(store.get_front());
                        store.pop();
                        temp.push(store.get_front() + temp.get_front());
                        store.pop();
                        store.push(temp.get_front());
                        temp.Clear();
                        store.show_all();
                        break;
                    case '-':
                        temp.push(store.get_front());
                        store.pop();
                        temp.push(store.get_front() - temp.get_front());
                        store.pop();
                        store.push(temp.get_front());
                        temp.Clear();
                        store.show_all();
                        break;
                    case '*':
                        temp.push(store.get_front());
                        store.pop();
                        temp.push(store.get_front() * temp.get_front());
                        store.pop();
                        store.push(temp.get_front());
                        temp.Clear();
                        store.show_all();
                        break;
                    case '/':
                        temp.push(store.get_front());
                        store.pop();
                        temp.push(store.get_front() / temp.get_front());
                        store.pop();
                        store.push(temp.get_front());
                        temp.Clear();
                        store.show_all();
                        break;
                    }
                }
        }
        return store.get_front();
    }
};