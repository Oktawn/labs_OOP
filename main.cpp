#include <vector>
#include "Par.cpp"
#include "Circle.cpp"

double Shape::sum_square = 0.0;

std::vector<Shape *> vector_shapes;

void interface();
int main()
{
    interface();
    std::cout << "bye!\n";
    system("pause>nul");
    return 0;
}

void interface()
{
    using std::cout;

    cout << "hello\n create a few shape different figure\n";
    int variable = 0;
    do
    {

        switch (variable)
        {
        case 1:
        {
            system("cls");
            cout << "enter coordinates point x,y and radius: ";
            double x, y, radius;
            std::cin >> x >> y >> radius;
            Circle *temp = new Circle(x, y, radius);
            vector_shapes.push_back(temp);
            vector_shapes.back()->show_characteristic();
            break;
        }
        case 2:
        {
            system("cls");
            cout << "enter coordinates first point: ";
            double x, y;
            std::cin >> x >> y;
            cout << "enter coordinates second point: ";
            double x1, y1;
            std::cin >> x1 >> y1;
            cout << "enter lenght one side: ";
            double side;
            std::cin >> side;
            Par *temp = new Par(x, y, x1, y1, side);
            vector_shapes.push_back(temp);
            vector_shapes.back()->show_characteristic();
            break;
        }
        case 3:
        {
            cout << "enter position: ";
            int pos;
            std::cin >> pos;
            if (pos > 0 && pos < vector_shapes.size())
                vector_shapes[pos]->show_characteristic();
            else
                std::cerr << "invalid index\n";
            break;
        }
        case 4:
        {
            cout << "enter position: ";
            int pos;
            std::cin >> pos;
            if (pos > 0 && pos < vector_shapes.size())
                vector_shapes[pos]->show_attributes();
            else
                std::cerr << "invalid index\n";
            break;
        }
        }
        cout << "select the appropriate action option:\n"
             << "1 - create circle figure\n"
             << "2 - create parralelogram figure\n"
             << "3 - show shapes characteristics by index\n"
             << "4 - show shapes attibutes by index\n"
             << "q - exit program\n";
    } while (std::cin >> variable);
}