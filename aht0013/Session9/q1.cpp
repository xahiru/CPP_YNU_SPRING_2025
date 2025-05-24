#include <iostream>
#include <cmath>
#include <stdexcept>

class Circle {
private:
    double radius;
    
    void validateRadius(double r) {
        if (r <= 0) {
            throw std::invalid_argument("Radius must be positive");
        }
    }

public:
    explicit Circle(double r = 1.0) {
        setRadius(r);
    }

    void setRadius(double r) {
        validateRadius(r);
        radius = r;
    }

    [[nodiscard]] double getRadius() const noexcept { return radius; }
    [[nodiscard]] double getArea() const noexcept { return M_PI * radius * radius; }
    [[nodiscard]] double getCircumference() const noexcept { return 2 * M_PI * radius; }
};

int main() {
    try {
        Circle c(5.0);
        std::cout << "Circle with radius " << c.getRadius() << ":\n";
        std::cout << "Area: " << c.getArea() << "\n";
        std::cout << "Circumference: " << c.getCircumference() << "\n";
    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << "\n";
        return 1;
    }
    return 0;
}