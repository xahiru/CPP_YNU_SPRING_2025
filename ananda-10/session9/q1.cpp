#include <iostream>
#include <cmath>

class Circle {
private:
    double radius;

public:
    Circle(double r) {
        radius = r;
    }
    void setRadius(double r) {
        radius = r;
    }
    double getRadius() const {
        return radius;
    }
    double calculateArea() const {
        return M_PI * radius * radius;
    }
    double calculateCircumference() const {
        return 2 * M_PI * radius;
    }
};

int main() {
    double r;
    std::cout << "Enter the radius of the circle: ";
    std::cin >> r;

    Circle circle(r);

    std::cout << "Area of the circle: " << circle.calculateArea() << std::endl;
    std::cout << "Circumference of the circle: " << circle.calculateCircumference() << std::endl;

    return 0;
}


