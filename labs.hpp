#pragma once
#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <iterator>

#include <list>
#include "CCall.cpp"

#include <map>
#include "Newpaper.hpp"

#define set_map int, Newpaper, std::less<int>

std::map<set_map>::iterator it_m;

void create_v(std::vector<int> &v)
{
    srand((int)time(nullptr));
    v.resize(rand() % 20);
    auto gen = []()
    { return (rand() % 150 + (-50)); };
    std::generate(v.begin(), v.end(), gen);
    // for (auto &i : v)
    //     i = rand() % 150 + (-50);
}

void zero_after_neg(const std::vector<int> &vec)
{
    int zero = 0;

    // for (auto &i : vec)
    //   zero+=((i)<0 && (i+sizeof(i))==0) ? 1 : 0;
    for (int i(1); i < vec.size(); i++)
        zero += (vec[i - 1] < 0 && vec[i] == 0) ? 1 : 0;
    std::cout << zero << "\n";
}

void mul_pos(const std::vector<int> &vec)
{
    double d = 1;
    std::for_each(vec.begin(), std::find_if(vec.begin(), vec.end(), [](int i)
                                            { return i < 0; }),
                  [&](int i)
                  { d *= i; });
    std::cout << d << "\n";
};

void compres_vec(std::vector<int> &vec, int k)
{
    vec.erase(std::remove_if(vec.begin(), vec.end(),
                             [&](int n)
                             { return n % k == 0; }),
              vec.end());
};