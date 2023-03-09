#include "List.hpp"

int main()
{
    List<int> temp;
    temp.Add_Head(15);
    temp.Add_Head(44);
    temp.Add_Tail(22);
    std::cout<<temp[3];
    system("pause>nul");
}
