#include <iostream>

class Rectangle {
private:
    double length;
    double width;

public:
    Rectangle(double l, double w) {
        length = l;
        width = w;
    }
    void setLength(double l) {
        length = l;
    }

    void setWidth(double w) {
        width = w;
    }
    double getLength() const {
        return length;
    }

    double getWidth() const {
        return width;
    }
    double calculateArea() const {
        return length * width;
    }

    double calculatePerimeter() const {
        return 2 * (length + width);
    }
};

int main() {
    double l, w;
    std::cout << "Enter the length of the rectangle: ";
    std::cin >> l;
    std::cout << "Enter the width of the rectangle: ";
    std::cin >> w;

    Rectangle rect(l, w);

    std::cout << "Area of the rectangle: " << rect.calculateArea() << std::endl;
    std::cout << "Perimeter of the rectangle: " << rect.calculatePerimeter() << std::endl;

    return 0;
}

