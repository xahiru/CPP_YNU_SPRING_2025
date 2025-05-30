#include <iostream>
#include <cmath>

using namespace std;

class Circle {
private:
    double radius;
    const double PI = 3.14159265358979323846;

public:
    Circle(double r) : radius(r) {}  //Constructor to initialize the radius
    double calculateArea() {
        return PI * radius * radius;
    }


    double calculateCircumference() {
        return 2 * PI * radius;            // Function to calculate the circumference of the circle
    }
    double getRadius() {
        return radius;
    }
};

int main() {
    double radius;
    cout << "Enter the radius of the circle: ";
    cin >> radius;

    Circle myCircle(radius);

    cout << "Area of the circle: " << myCircle.calculateArea() << endl;
    cout << "Circumference of the circle: " << myCircle.calculateCircumference() << endl;

    return 0;
}