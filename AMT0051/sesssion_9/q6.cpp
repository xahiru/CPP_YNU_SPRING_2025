#include <iostream>
#include <cmath>
#include <iomanip>

class Shape {
public:
    virtual ~Shape() {}
    virtual double area() const = 0;
    virtual double perimeter() const = 0;
    virtual void display() const {
        std::cout << "Shape Information:" << std::endl;
    }
};

class Circle : public Shape {
private:
    double radius;
public:
    Circle(double r) : radius(r) {}
    double area() const override {
        return M_PI * radius * radius;
    }
    double perimeter() const override {
        return 2 * M_PI * radius;
    }
    void display() const override {
        std::cout << "\n--- Circle ---" << std::endl;
        std::cout << "Radius: " << radius << std::endl;
        std::cout << "Area: " << area() << std::endl;
        std::cout << "Circumference: " << perimeter() << std::endl;
    }
};

class Rectangle : public Shape {
private:
    double length;
    double width;
public:
    Rectangle(double l, double w) : length(l), width(w) {}
    double area() const override {
        return length * width;
    }
    double perimeter() const override {
        return 2 * (length + width);
    }
    void display() const override {
        std::cout << "\n--- Rectangle ---" << std::endl;
        std::cout << "Length: " << length << ", Width: " << width << std::endl;
        std::cout << "Area: " << area() << std::endl;
        std::cout << "Perimeter: " << perimeter() << std::endl;
    }
};

class Triangle : public Shape {
private:
    double sideA, sideB, sideC;
public:
    Triangle(double a, double b, double c) : sideA(a), sideB(b), sideC(c) {}
    double area() const override {
        double s = (sideA + sideB + sideC) / 2.0;
        return std::sqrt(s * (s - sideA) * (s - sideB) * (s - sideC));
    }
    double perimeter() const override {
        return sideA + sideB + sideC;
    }
    void display() const override {
        std::cout << "\n--- Triangle ---" << std::endl;
        std::cout << "Sides: " << sideA << ", " << sideB << ", " << sideC << std::endl;
        std::cout << "Area: " << area() << std::endl;
        std::cout << "Perimeter: " << perimeter() << std::endl;
    }
};

int main() {
    std::cout << std::fixed << std::setprecision(2);
    Shape* shapes[3];
    shapes[0] = new Circle(5.0);
    shapes[1] = new Rectangle(4.0, 6.0);
    shapes[2] = new Triangle(3.0, 4.0, 5.0);
    for (int i = 0; i < 3; ++i) {
        shapes[i]->display();
        delete shapes[i];
    }
    return 0;
}
