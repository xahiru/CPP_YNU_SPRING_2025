#include <iostream>
using namespace std;

class Rectangle {
private:
    double length;
    double width;

public:
    Rectangle(double l, double w) : length(l), width(w) {}

    double area() {
        return length * width;
    }

    double perimeter() {
        return 2 * (length + width);
    }
};

int main() {
    Rectangle rectangle(4, 5);
    cout << "Area: " << rectangle.area() << endl;
    cout << "Perimeter: " << rectangle.perimeter() << endl;
    return 0;
}
