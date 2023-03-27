#include "Deque.hpp"

int main()
{
    Deque<int> deq;
    deq.push_front(44);
    deq.push_back(33);
    deq.push_back(11);
    deq.push_back(13);
    deq.push_back(5);
    deq.push_front(22);
    deq.show_all();
    std::cout<<deq.is_empty();
   

    system("pause>nul");
    return 0;
}