#include "Circle.hpp"

void Circle::move(double z)
{
    x += z, y += z;
}

void Circle::scale(double z)
{
    x *= z, y *= z, radius *= z;
}

void Circle::show_attributes()
{
    std::cout
        << "x: " << x << "\n"
        << "y: " << y << "\n"
        << "radius: " << radius << "\n";
}

void Circle::show_characteristic()
{
    std::cout
        << "square: " << get_square() << "\n"
        << "lenght: " << get_perimetr() << "\n"
        << "diametr: " << get_diametr() << "\n";
}

double Circle::get_square()
{
    return M_PI * radius * radius;
}

double Circle::get_perimetr()
{
    return 2 * M_PI * radius;
}

double Circle::get_diametr()
{
    return 2 * radius;
}

double Circle::get_sector_square(double p)
{
    return 1 / 2 * p * radius;
}
