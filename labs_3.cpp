#include "Newpaper.hpp"

int main()
{
    Newpaper temp;
    
    temp.Add_author("bbb");

    temp.Change_author("bbb", "qq");

    temp.Show_author();

    system("pause>nul");
    return 0;
}