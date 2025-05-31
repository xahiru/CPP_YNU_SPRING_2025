#include <iostream>
#include <cmath>

class Circle {
private:
    double radius;

public:

    Circle(double r) {
        radius = r;
    }

    double getArea() {
        return M_PI * radius * radius;
    }

    double getCircumference() {
        return 2 * M_PI * radius;
    }

    void display() {
        std::cout << "Radius: " << radius << std::endl;
        std::cout << "Area: " << getArea() << std::endl;
        std::cout << "Circumference: " << getCircumference() << std::endl;
    }
};

int main() {
    double r;
    std::cout << "Enter the radius of the circle: ";
    std::cin >> r;

    Circle circle(r);
    circle.display();

    return 0;
}
