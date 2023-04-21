#pragma once

#define _USE_MATH_DEFINES
#define trasn 180.0 / M_PI
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
	virtual double get_square() = 0;
	virtual ~Shape() {}

	static double sum_sq()
	{
		return sum_square;
	}

	bool operator>(Shape& S)
	{
		return this->get_square() > S.get_square();
	}
};
