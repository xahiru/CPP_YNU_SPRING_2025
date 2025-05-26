#include <iostream>

class Rectangle {
private:
    double length;
    double width;

public:
    Rectangle(double l, double w) : length(l > 0 ? l : 0), width(w > 0 ? w : 0) {
        if (l <= 0 || w <= 0) {
            std::cout << "Invalid dimensions. Setting to 0." << std::endl;
        }
    }

    double calculateArea() const {
        return length * width;
    }

    double calculatePerimeter() const {
        return 2 * (length + width);
    }

    double getLength() const {
        return length;
    }

    double getWidth() const {
        return width;
    }

    void setDimensions(double l, double w) {
        if (l > 0 && w > 0) {
            length = l;
            width = w;
        } else {
            std::cout << "Dimensions must be positive." << std::endl;
        }
    }
};

int main() {
    double l, w;
    std::cout << "Enter length and width of rectangle: ";
    std::cin >> l >> w;

    Rectangle rect(l, w);

    std::cout << "\nRectangle Details:" << std::endl;
    std::cout << "Length: " << rect.getLength() << std::endl;
    std::cout << "Width: " << rect.getWidth() << std::endl;
    std::cout << "Area: " << rect.calculateArea() << std::endl;
    std::cout << "Perimeter: " << rect.calculatePerimeter() << std::endl;

    return 0;
}