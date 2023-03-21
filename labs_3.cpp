#include "Newpaper.hpp"

int main()
{
    List<Newpaper> gg;
    Newpaper temp;
    
    temp.Add_author("bbb");

    temp.Change_author("bbb", "qq");

    gg.Add_Head(temp);
    gg.Show_on_Head();

    system("pause>nul");
    return 0;
}