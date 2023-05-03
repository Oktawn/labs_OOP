#include "labs.hpp"

int main()
{

    std::vector<int> vec;

    create_v(vec);
    std::copy(vec.begin(), vec.end(), std::ostream_iterator<int, char>(std::cout, " "));
    std::cout << "\nzero:";
    zero_after_neg(vec);
    std::cout << "mul: ";
    mul_pos(vec);
    compres_vec(vec, 5);
    std::copy(vec.begin(), vec.end(), std::ostream_iterator<int, char>(std::cout, " "));
    std::cout << "\n";

    std::list<CCall> call;

    CCall tes;
    call.push_back(tes);
    call.back().show_call();
    std::cout << "\n";
    Newpaper pap;

    std::map<set_map> map_pap;
    map_pap[555] = pap;
    
    it_m = map_pap.begin();
    std::cout << (*it_m).second << "\n";
    system("pause>nul");
    return 0;
}