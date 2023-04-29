#include "work_1.cpp"

using namespace work_1;
// using namespace work_3;

int main()
{
    std::vector<int> vec;
    std::list<CCall> paper;
    create(vec);
    zero_after_neg(vec);
    mul_pos(vec);
    compres_vec(vec, 5);

    CCall call;
    paper.push_back(call);
    paper.back().show_call();

    Newpaper pap;

    system("pause>nul");
    return 0;
}