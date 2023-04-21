#include "basic_figure.hpp"

class Circle : public Shape
{

	double
		x,
		y,
		radius;

public:
	Circle(double x, double y, double radius)
		: x(x), y(y), radius(radius) 
	{
		sum_square += get_square();
	}
	Circle() : x(0), y(0), radius(0) {}
	~Circle() {}

	void move(double);
	void scale(double);
	void show_attributes();
	void show_characteristic();

	double get_square();
	double get_diametr();
	double get_perimetr();
	double get_sector_square(double p);

	void set_x(double x) { this->x = x; }
	void set_y(double y) { this->y = y; }
	void set_radius(double radius) { this->radius = radius; }
};