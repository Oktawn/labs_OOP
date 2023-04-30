#include "labs.hpp"

int main()
{

    std::vector<int> vec;
    create_v(vec);
    zero_after_neg(vec);
    mul_pos(vec);

    std::list<CCall> call;

    CCall tes;
    call.push_back(tes);
    call.back().show_call();
    std::cout << "\n";
    Newpaper pap;

    std::map<set_map> map_pap;
    map_pap[555]=pap;
    it_m = map_pap.begin();
    std::cout<< (*it_m).second << "\n";

    return 0;
}