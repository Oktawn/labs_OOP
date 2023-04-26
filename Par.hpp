#include "basic_figure.hpp"

class Par : public Shape
{
private:
	Point x, x1;
	double

		lenght_side;

public:
	Par(double x, double y, double x1, double y1, double side)
		: x(x, y), x1(x1, y1), lenght_side(side)
	{
		sum_square += get_square();
	}
	Par() : x(0, 0), x1(0, 0), lenght_side(0) {}
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

	void set_side(double side) { this->lenght_side = side; }
};