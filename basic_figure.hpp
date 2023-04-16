#pragma once

#define _USE_MATH_DEFINES
#include <iostream>
#include <cmath>

class Shape
{
public:
    static double sum_square;
    virtual void move(double) = 0;
    virtual void scale(double) = 0;
    virtual void show_attributes() = 0;
    virtual void show_characteristic() = 0;
};
