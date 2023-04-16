#include "basic_figure.hpp"

class Par : public Shape
{
private:
    double
        square,
        perimetr,
        lenght,
        height,
        width,
        lenght_diagonal,
        corn1, corn2;

public:
    void move(double);
    void scale(double);
    void show_attributes();
    void show_characteristic();
};