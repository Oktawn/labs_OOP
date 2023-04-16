#include "basic_figure.hpp"

class Circle : Shape
{

    double
        x,
        y,
        radius;

public:
    Circle(double x, double y, double radius)
        : x(x), y(y), radius(radius) {}
    ~Circle() {}

    void move(double);
    void scale(double);
    void show_attributes();
    void show_characteristic();

    double get_square();
    double get_perimetr();
    double get_diametr();
    double get_sector_square(double p);

    double set_x(double x) { this->x = x; }
    double set_y(double y) { this->y = y; }
    double set_radius(double radius) { this->radius = radius; }
};