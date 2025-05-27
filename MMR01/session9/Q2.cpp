#include <iostream>

class Rectangle {
private:
    double length;
    double width;

public:
    // Constructor to initialize length and width
    Rectangle(double l = 0.0, double w = 0.0) {
        setLength(l);
        setWidth(w);
    }

    // Setter for length with validation
    void setLength(double l) {
        if (l >= 0) {
            length = l;
        } else {
            std::cout << "Error: Length cannot be negative. Setting to 0." << std::endl;
            length = 0;
        }
    }

    // Setter for width with validation
    void setWidth(double w) {
        if (w >= 0) {
            width = w;
        } else {
            std::cout << "Error: Width cannot be negative. Setting to 0." << std::endl;
            width = 0;
        }
    }

    // Getters
    double getLength() const { return length; }
    double getWidth() const { return width; }

    // Calculate area (length × width)
    double calculateArea() const {
        return length * width;
    }

    // Calculate perimeter (2 × (length + width))
    double calculatePerimeter() const {
        return 2 * (length + width);
    }

    // Display rectangle information
    void display() const {
        std::cout << "\nRectangle Details:\n";
        std::cout << "Length: " << length << "\n";
        std::cout << "Width: " << width << "\n";
        std::cout << "Area: " << calculateArea() << "\n";
        std::cout << "Perimeter: " << calculatePerimeter() << "\n";
    }
};

int main() {
    Rectangle rect; // Create a Rectangle object

    // Get dimensions from user
    double l, w;
    std::cout << "Enter length of rectangle: ";
    std::cin >> l;
    std::cout << "Enter width of rectangle: ";
    std::cin >> w;

    rect.setLength(l);
    rect.setWidth(w);
    rect.display();

    return 0;
}