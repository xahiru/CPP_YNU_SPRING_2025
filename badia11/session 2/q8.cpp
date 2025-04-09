#include <iostream>
#include <cmath>
#include <string>
using namespace std;

// Function for Q1: Volume of a Sphere
void volume_of_sphere() {
    float radius, volume;
    const float PI = 3.14159;
    cout << "Input the radius of a sphere: ";
    cin >> radius;
    volume = (4.0 / 3.0) * PI * pow(radius, 3);
    cout << "The volume of a sphere is: " << volume << endl;
}

// Function for Q2: Volume of a Cube
void volume_of_cube() {
    int side, volume;
    cout << "Input the side of a cube: ";
    cin >> side;
    volume = side * side * side;
    cout << "The volume of a cube is: " << volume << endl;
}

// Function for Q3: Area and Perimeter of a Rectangle
void area_and_perimeter_of_rectangle() {
    int length, width, area, perimeter;
    cout << "Input the length of the rectangle: ";
    cin >> length;
    cout << "Input the width of the rectangle: ";
    cin >> width;
    area = length * width;
    perimeter = 2 * (length + width);
    cout << "The area of the rectangle is: " << area << endl;
    cout << "The perimeter of the rectangle is: " << perimeter << endl;
}

// Function for Q4: Area and Circumference of a Circle
void area_and_circumference_of_circle() {
    float radius, area, circumference;
    const float PI = 3.14159;
    cout << "Input the radius of a circle: ";
    cin >> radius;
    area = PI * pow(radius, 2);
    circumference = 2 * PI * radius;
    cout << "The area of the circle is: " << area << endl;
    cout << "The circumference of the circle is: " << circumference << endl;
}

// Function for Q5: Print Numbers in Words
void print_numbers_in_words() {
    int n;
    cout << "Enter a number: ";
    cin >> n;
    if (n >= 1 && n <= 9) {
        string words[] = {"one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};
        cout << words[n - 1] << endl;
    } else {
        cout << "Greater than 9" << endl;
    }
}

// Function for Q6: Print Numbers and Check for Even or Odd
void print_numbers_and_check_even_odd() {
    int a, b;
    cout << "Enter the range (two integers): ";
    cin >> a >> b;
    for (int i = a; i <= b; i++) {
        if (i >= 1 && i <= 9) {
            string words[] = {"one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};
            cout << words[i - 1] << endl;
        } else {
            if (i % 2 == 0) {
                cout << "even" << endl;
            } else {
                cout << "odd" << endl;
            }
        }
    }
}

int main() {
    // Call each function to test
    volume_of_sphere();
    volume_of_cube();
    area_and_perimeter_of_rectangle();
    area_and_circumference_of_circle();
    print_numbers_in_words();
    print_numbers_and_check_even_odd();
    return 0;
}
