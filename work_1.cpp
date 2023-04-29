#include <iostream>

#include <vector>
#include <algorithm>

#include <list>
#include "CCall.h"

#include <set>
#include <map>
#include "Newpaper.hpp"
#include <iterator>

#define cont Newpaper, int, std::less<int>

namespace work_1
{

    void create (std::vector<int> &v)
    {
        std::srand(time(0));
        for (auto &i : v)
            i = rand() % (1001 - 500);
    };

    void zero_after_neg(const std::vector<int> &vec)
    {
        int zero = 0;
        for (int i(1); i < vec.size(); i++)
            zero += vec[i] < 0 && vec[i] == 0 ? 1 : 0;
        std::cout << zero;
    }
    // double mul_pos_last_neg(const std::vector<int> &vec)
    // {
    //     double d = 0.0;
    //     for (auto &i : vec)
    //         if (i > 0)
    //             d *= i;
    //         else
    //             break;
    //     return d;
    // }
    void mul_pos (const std::vector<int> &vec)
    {
        double d = 0.0;
        for (auto &i : vec)
            if (i > 0)
                d *= i;
            else
                break;
        std::cout << d;
    };

    void compres_vec (std::vector<int> &vec, int k)
    {
        int size = vec.size();
        for (auto &i : vec)
            i = (i == k) ? 0 : i;

        vec.erase(std::remove_if(vec.begin(), vec.end(), 0), vec.end());
        vec.resize(size);
    };
}

//namespace work_3
//{
//#define cont Newpaper, int, std::less<int>
//#define m_cont int, Newpaper, std::less<int>
//    typedef std::set<cont> int_set;
//    typedef std::map<m_cont> int_map;
//    int_set::const_iterator it_s;
//    int_map::const_iterator it_m;
//}