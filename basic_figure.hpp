#pragma once
#include "List.hpp"

template <typename T>
class Shape
{
public:
    Shape() {}
    static double sum_square;
    void move(double) = 0;
    void scale(double) = 0;
    void show_attributes() = 0;
    void show_characteristic() = 0;

    friend bool operator>(T F1, T F2);
};
