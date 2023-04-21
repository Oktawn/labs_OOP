#include "basic_figure.hpp"


class Par : public Shape
{
private:
	double
		x,
		x1,

		y,
		y1,

		lenght_side;

public:
	Par(double x, double y, double x1, double y1, double side)
		: x(x), y(y), x1(x1), y1(y1), lenght_side(side) 
	{
		sum_square += get_square();
	}
	Par() : x(0), y(0), x1(0), y1(0), lenght_side(0) {}
	~Par() {}

	void move(double);
	void scale(double);
	void show_attributes();
	void show_characteristic();

	double get_perimetr();
	double get_diagonal();
	double get_diagonal_2();
	double get_square();
	double get_lenght();
	double get_height();
	double get_wight();
	double get_angular_a();
	double get_angular_b();

	void set_x(double x) { this->x = x; }
	void set_y(double y) { this->y = y; }
	void set_side(double side) { this->lenght_side = side; }
};