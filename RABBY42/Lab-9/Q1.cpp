#include <iostream>
#include <cmath>
using namespace std;

class Circle {
private:
    double radius;
public:
    Circle(double r) : radius(r) {}
    double area() { return M_PI * radius * radius; }
    double circumference() { return 2 * M_PI * radius; }
};

int main() {
    Circle c(5);
    cout << "Area: " << c.area() << endl;
    cout << "Circumference: " << c.circumference() << endl;
    return 0;
}