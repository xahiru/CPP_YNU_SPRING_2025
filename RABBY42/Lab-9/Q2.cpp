#include <iostream>
using namespace std;

class Rectangle {
private:
    double length, width;
public:
    Rectangle(double l, double w) : length(l), width(w) {}
    double area() { return length * width; }
    double perimeter() { return 2 * (length + width); }
};

int main() {
    Rectangle r(4, 5);
    cout << "Area: " << r.area() << endl;
    cout << "Perimeter: " << r.perimeter() << endl;
    return 0;
}