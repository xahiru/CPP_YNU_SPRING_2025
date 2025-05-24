#include <iostream>
using namespace std;

class Circle {
private:
    double radius;

public:
    Circle(double r) : radius(r) {}

    double area() {
        return 3.14159 * radius * radius;
    }

    double circumference() {
        return 2 * 3.14159 * radius;
    }
};

int main() {
    Circle circle(5);
    cout << "Area: " << circle.area() << endl;
    cout << "Circumference: " << circle.circumference() << endl;
    return 0;
}
