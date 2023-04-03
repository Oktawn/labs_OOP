#pragma once
#include "Stack.hpp"
#include "Deque.hpp"

void visual()
{
    char operands;
    Stack<double> store, temp;
    std::string push;
    std::cout << "enter numbers: ";
    while (true)
    {
        while (std::cin >> push)
        {
            if (!ispunct((push[0])))
                store.push((stof(push)));
            else
                break;
        }
        operands = (push[0]);
        switch (operands)
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
        std::cout << "if go out enter q : ";
        std::cin >> push;
        if (push[0]=='q')
            break;
        std::cout << "enter numbers or operand: \n";
    }
}
