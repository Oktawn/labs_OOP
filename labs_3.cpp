#include "Newpaper.hpp"

int main()
{
    List<int> temp;
    temp.Add_Head(15);
    temp.Add_Head(44);
    temp.Add_Tail(22);
    std::cout << temp[2] << std::endl;

    // temp.Show_on_Head();

    system("pause>nul");
}
