#pragma once
#include <iostream>
#include <vector>
#include <algorithm>

#include <list>
#include "CCall.hpp"

#include <map>
#include "Newpaper.hpp"

#define set_map int, Newpaper,std::less<int>

std::map<set_map>::iterator it_m;

void create_v(std::vector<int> &v)
{
    srand((int)time(nullptr));
    v.resize(rand() % 20);
    for (auto &i : v)
        i = rand() % 150 + (-50);
}

void zero_after_neg(const std::vector<int> &vec)
{
    int zero = 0;
    for (int i(1); i < vec.size(); i++)
        zero += (vec[i - 1] < 0 && vec[i] == 0) ? 1 : 0;
    std::cout << zero << "\n";
}

void mul_pos(const std::vector<int> &vec)
{
    double d = 1;
    for (auto &i : vec)
    {
        if (i > 0)
            d *= i;
        else
            break;
    }
    std::cout << d << "\n";
};