#include <iostream>
#include <cmath>
#include <stdexcept>
#include <string>

class Circle {
private:
    double radius;
    
    void validateRadius(double r) const {
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

    void display() const {
        std::cout << "Circle:\n"
                  << "  Radius: " << radius << "\n"
                  << "  Area: " << getArea() << "\n"
                  << "  Circumference: " << getCircumference() << "\n";
    }
};

int main() {
    try {
        Circle c(5.0);
        c.display();
        
        Circle invalid(0.0);  
    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << "\n";
        return EXIT_FAILURE;
    }
    return EXIT_SUCCESS;
}