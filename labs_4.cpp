#include "Deque.hpp"

int main()
{
    Deque<int> deq;

    deq.push_front(5);
    deq.push_back(22);
    deq.push_back(11);
    deq.show_all();
    

    system("pause>nul");
    return 0;
}