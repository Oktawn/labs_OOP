#include "basic_figure.hpp"

class Par : public Shape
{
private:
    double
        x,
        y,
        lenght_side;

public:
    Par(double x, double y, double side)
        : x(x), y(y), lenght_side(side) {}
    Par() : x(0), y(0), lenght_side(0) {}

    void move(double);
    void scale(double);
    void show_attributes();
    void show_characteristic();

    double get_perimetr();
    double get_diagonal();
    double get_square();
    double get_lenght();
    double get_height();
    double get_wight();

    double set_x(double x) { this->x = x; }
    double set_y(double y) { this->y = y; }
    double set_side(double side) { this->lenght_side = side; }
};