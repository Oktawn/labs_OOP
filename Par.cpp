#include "Par.hpp"

void Par::move(double z)
{
	x.x += z, x.y += z;
	x1.x += z, x1.y += z;
}

void Par::scale(double z)
{
	double temp = get_square();
	x.x *= z, x.y *= z, lenght_side *= z;
	x1.x *= z, x1.y *= z;
	sum_square += get_square() - temp;
}

void Par::show_attributes()
{
	std::cout
		<< "x0: " << x.x << "\n"
		<< "y0: " << x.y << "\n"
		<< "x1: " << x1.x << "\n"
		<< "y1: " << x1.y << "\n"
		<< "side: " << lenght_side << "\n";
}

void Par::show_characteristic()
{
	std::cout
		<< "wight: " << get_wight() << "\n"
		<< "height: " << get_height() << "\n"
		<< "lenght: " << get_lenght() << "\n"
		<< "square: " << get_square() << "\n"
		<< "perimetr: " << get_perimetr() << "\n"
		<< "diagonal: " << get_diagonal() << "\n"
		<< "diagonal_2: " << get_diagonal_2() << "\n"
		<< "angular a: " << get_angular_a() << "\n"
		<< "angular b: " << get_angular_b() << "\n"
		<< "\n";
}

double Par::get_perimetr()
{
	return 2.0 * (get_lenght() + get_wight());
}

double Par::get_diagonal()
{
	return sqrt(pow((x1.x - x.x), 2) + pow((x1.y - x.y), 2));
}

double Par::get_diagonal_2()
{
	return sqrt(pow(((x1.x - lenght_side) - (x.x + lenght_side)), 2) +
				pow((x1.y - x.y), 2));
}

double Par::get_square()
{
	return std::max(get_lenght(), get_wight()) * get_height();
}

double Par::get_lenght()
{
	return lenght_side;
}

double Par::get_height()
{
	return abs(x1.y - x.y);
}

double Par::get_wight()
{
	return sqrt(
		(pow(get_diagonal(), 2) + pow(get_diagonal_2(), 2) -
		 2 * pow(lenght_side, 2)) /
		2);
}

double Par::get_angular_a()
{
	return asin((get_square() / (get_lenght() * get_wight()))) * trasn;
}

double Par::get_angular_b()
{
	return 180.0 - get_angular_a();
}
