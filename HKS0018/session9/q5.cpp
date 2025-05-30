#include <iostream>
#include <cmath>

using namespace std;

class Shape {
public:
    virtual double calculateArea() const = 0;  // Pure virtual function
    virtual double calculatePerimeter() const = 0;  // Pure virtual function
    
    virtual ~Shape() {}
    
    // Function to display shape information
    virtual void display() const {
        cout << "Shape: ";
    }
};

class Circle : public Shape {
private:
    double radius;
    
public:
    Circle(double r) : radius(r) {
        if (radius <= 0) {
            cout << "Invalid radius! Setting to default 1.0" << endl;
            radius = 1.0;
        }
    }
    
    double calculateArea() const override {
        return M_PI * radius * radius;
    }
    
    double calculatePerimeter() const override {
        return 2 * M_PI * radius;
    }
    
    void display() const override {
        Shape::display();
        cout << "Circle (Radius: " << radius << ")" << endl;
    }
};

class Rectangle : public Shape {
private:
    double length;
    double width;
    
public:
    Rectangle(double l, double w) : length(l), width(w) {
        if (length <= 0 || width <= 0) {
            cout << "Invalid dimensions! Setting to default 1.0" << endl;
            length = 1.0;
            width = 1.0;
        }
    }
    
    double calculateArea() const override {
        return length * width;
    }
    
    double calculatePerimeter() const override {
        return 2 * (length + width);
    }
    
    void display() const override {
        Shape::display();
        cout << "Rectangle (Length: " << length << ", Width: " << width << ")" << endl;
    }
};

class Triangle : public Shape {
private:
    double side1, side2, side3;
    
public:
    Triangle(double s1, double s2, double s3) : side1(s1), side2(s2), side3(s3) {
        if (side1 <= 0 || side2 <= 0 || side3 <= 0 || 
            (side1 + side2 <= side3) || 
            (side1 + side3 <= side2) || 
            (side2 + side3 <= side1)) {
            cout << "Invalid triangle sides! Setting to default equilateral (3,3,3)" << endl;
            side1 = side2 = side3 = 3.0;
        }
    }
    
    double calculateArea() const override {

        double s = calculatePerimeter() / 2;
        return sqrt(s * (s - side1) * (s - side2) * (s - side3));
    }
    
    double calculatePerimeter() const override {
        return side1 + side2 + side3;
    }
    
    void display() const override {
        Shape::display();
        cout << "Triangle (Sides: " << side1 << ", " << side2 << ", " << side3 << ")" << endl;
    }
};

int main() {
    Shape* shapes[3];
    
    shapes[0] = new Circle(5.0);
    shapes[1] = new Rectangle(4.0, 6.0);
    shapes[2] = new Triangle(3.0, 4.0, 5.0);
    
    // Demonstrate polymorphism
    for (int i = 0; i < 3; ++i) {
        shapes[i]->display();
        cout << "Area: " << shapes[i]->calculateArea() << endl;
        cout << "Perimeter: " << shapes[i]->calculatePerimeter() << endl;
        cout << endl;
    }

    cout << "\nTesting invalid shapes:" << endl;
    Circle invalidCircle(-2.0);
    Rectangle invalidRect(0.0, -1.0);
    Triangle invalidTriangle(1.0, 2.0, 5.0);
    
    invalidCircle.display();
    cout << "Area: " << invalidCircle.calculateArea() << endl;
    
    // Clean up memory
    for (int i = 0; i < 3; ++i) {
        delete shapes[i];
    }
    
    
    return 0;
}