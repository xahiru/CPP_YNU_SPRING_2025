#include <iostream>
#include <stdexcept>

class Rectangle {
private:
    double length;
    double width;
    
    void validateDimensions(double l, double w) {
        if (l <= 0 || w <= 0) {
            throw std::invalid_argument("Dimensions must be positive");
        }
    }

public:
    Rectangle(double l = 1.0, double w = 1.0) {
        setDimensions(l, w);
    }

    void setDimensions(double l, double w) {
        validateDimensions(l, w);
        length = l;
        width = w;
    }

    [[nodiscard]] std::pair<double, double> getDimensions() const noexcept { 
        return {length, width}; 
    }
    
    [[nodiscard]] double getArea() const noexcept { return length * width; }
    [[nodiscard]] double getPerimeter() const noexcept { return 2 * (length + width); }
};

int main() {
    try {
        Rectangle r(4.0, 5.0);
        auto [l, w] = r.getDimensions();
        std::cout << "Rectangle " << l << "x" << w << ":\n";
        std::cout << "Area: " << r.getArea() << "\n";
        std::cout << "Perimeter: " << r.getPerimeter() << "\n";
    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << "\n";
        return 1;
    }
    return 0;
}