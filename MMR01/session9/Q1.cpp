#include <iostream>
#include <cmath> 

class Circle {
private:
    double radius; 

public:
    Circle(double r = 0.0) {
        setRadius(r); // Use setter to ensure validation
    }

    // Setter method with validation
    void setRadius(double r) {
        if (r >= 0) {
            radius = r;
        } else {
            std::cout << "Error: Radius cannot be negative. Setting to 0." << std::endl;
            radius = 0;
        }
    }

    // Getter method
    double getRadius() const {
        return radius;
    }

    // Calculate area (πr²)
    double getArea() const {
        return M_PI * radius * radius;
    }

    // Calculate circumference (2πr)
    double getCircumference() const {
        return 2 * M_PI * radius;
    }

    // Display circle information
    void display() const {
        std::cout << "Circle with radius " << radius << ":\n";
        std::cout << "- Area: " << getArea() << "\n";
        std::cout << "- Circumference: " << getCircumference() << "\n";
    }
};

int main() {
    // Create a Circle object
    Circle myCircle;

    double radius;
    std::cout << "Enter the radius of the circle: ";
    std::cin >> radius;

    myCircle.setRadius(radius);

    myCircle.display();

    return 0;
}