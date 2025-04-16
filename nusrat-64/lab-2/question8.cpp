#include <iostream>
#include <cmath>
#define M_PI 3.14159265358979323846
using namespace std;

// 1. Volume of a Sphere
float volume_of_sphere(float radius) {
    return (4.0 / 3) * M_PI * pow(radius, 3);
}

// 2. Volume of a Cube
float volume_of_cube(float side) {
    return pow(side, 3);
}

// 3. Area and Perimeter of a Rectangle
void rectangle_area_perimeter(float length, float width) {
    float area = length * width;
    float perimeter = 2 * (length + width);
    cout << "Area: " << area << ", Perimeter: " << perimeter << endl;
}

// 4. Area and Circumference of a Circle
void circle_area_circumference(float radius) {
    float area = M_PI * pow(radius, 2);
    float circumference = 2 * M_PI * radius;
    cout << "Area: " << area << ", Circumference: " << circumference << endl;
}

// 5. Print Numbers in Words
void print_number_word(int n) {
    if (n > 9) cout << "Greater than 9" << endl;
    else {
        string words[] = {"one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};
        cout << words[n - 1] << endl;
    }
}

// 6. Print Numbers and Check Even/Odd
void print_numbers_and_check(int a, int b) {
    for (int n = a; n <= b; n++) {
        if (n <= 9) print_number_word(n);
        else if (n % 2 == 0) cout << "even" << endl;
        else cout << "odd" << endl;
    }
}

int main() {
    cout << "Volume of Sphere (radius 6): " << volume_of_sphere(6) << endl;
    cout << "Volume of Cube (side 5): " << volume_of_cube(5) << endl;
    rectangle_area_perimeter(10, 15);
    circle_area_circumference(5);
    print_number_word(5);
    print_numbers_and_check(8, 11);
    return 0;
}