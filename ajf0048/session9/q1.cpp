#include <iostream>
#include <cmath>
using namespace std;

class Circle {
private:
    double radius;

public:
    Circle(double r) : radius(r) {}

    double getArea() {
        return M_PI * radius * radius;
    }

    double getCircumference() {
        return 2 * M_PI * radius;
    }
};

int main() {
    Circle circle(5.0);
    cout << "Area: " << circle.getArea() << endl;
    cout << "Circumference: " << circle.getCircumference() << endl;
    return 0;
}
