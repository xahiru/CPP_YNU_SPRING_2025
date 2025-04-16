#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

double volume_of_sphere(double radius) {
    return (4.0 / 3.0) * M_PI * pow(radius, 3);
}

double volume_of_cube(double side) {
    return side * side * side;
}

void area_and_perimeter_of_rectangle(double length, double width, double &area, double &perimeter) {
    area = length * width;
    perimeter = 2 * (length + width);
}

void area_and_circumference_of_circle(double radius, double &area, double &circumference) {
    area = M_PI * pow(radius, 2);
    circumference = 2 * M_PI * radius;
}

void print_number_in_word(int n) {
    if (n > 1 && n < 9) {
        switch (n) {
            case 2: cout << "two"; break;
            case 3: cout << "three"; break;
            case 4: cout << "four"; break;
            case 5: cout << "five"; break;
            case 6: cout << "six"; break;
            case 7: cout << "seven"; break;
            case 8: cout << "eight"; break;
        }
    } else {
        cout << "Greater than 9";
    }
}

void check_even_or_odd(int n) {
    if (n % 2 == 0) {
        cout << n << " is even." << endl;
    } else {
        cout << n << " is odd." << endl;
    }
}

int main() {
    double radius;
    cout << "Input the radius of a sphere: ";
    cin >> radius;
    cout << fixed << setprecision(2);
    cout << "The volume of a sphere is: " << volume_of_sphere(radius) << endl;

    double side;
    cout << "Input the side of a cube: ";
    cin >> side;
    cout << "The volume of a cube is: " << volume_of_cube(side) << endl;

    double length, width, area, perimeter;
    cout << "Input the length of the rectangle: ";
    cin >> length;
    cout << "Input the width of the rectangle: ";
    cin >> width;
    area_and_perimeter_of_rectangle(length, width, area, perimeter);
    cout << "The area of the rectangle is: " << area << endl;
    cout << "The perimeter of the rectangle is: " << perimeter << endl;

    double circumference; 
    cout << "Input the radius of a circle: ";
    cin >> radius;
    area_and_circumference_of_circle(radius, area, circumference);
    cout << "The area of the circle is: " << area << endl;
    cout << "The circumference of the circle is: " << circumference << endl;

    int n;
    cout << "Input a number (greater than 1 and less than 9): ";
    cin >> n;
    print_number_in_word(n);
    cout << endl;

    cout << "Input a number to check if it's even or odd: ";
    cin >> n;
    check_even_or_odd(n);

    return 0;
}
