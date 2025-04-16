#include <iostream>

using namespace std;

#define PI 3.1415

double Vsphere(double r){

    return (4.0/3.0)*PI*r*r*r;

}

double calculateCubeVolume(double n) {
    return n * n* n;
}

double calculateArea(double r) {
    return PI * r * r;
}
double calculateCircumference(double r) {
    return 2 * PI * r;
}
double calculateRectangleArea(double l, double w) {
    return l * w;
}

double calculateRectanglePerimeter(double l, double w) {
    return 2 * (l + w);
}


string numberToWord(int n) {
    string num_words[] = {"one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};
    if (n >= 1 && n <= 9)
        return num_words[n - 1];
    else
        return "";
}

string evenOrOdd(int n) {
    return (n % 2 == 0) ? "even" : "odd";
}

int main() {
    int select;
    
    cout << "Choose an operation:" << endl;
    cout << "1. Calculate Sphere Volume" << endl;
    cout << "2. Calculate Cube Volume" << endl;
    cout << "3. Calculate Circle Area & Circumference" << endl;
    cout << "4. Calculate Rectangle Area & Perimeter" << endl;
    cout << "5. Number to Word / Even-Odd" << endl;
    cout << "Enter your choice (1-5): ";
    cin >> select;

    switch (select) {
        case 1: {
            double radius;
            cout << "\nEnter radius of the sphere: ";
            cin >> radius;
            cout << "Volume of Sphere: " << Vsphere(radius) << endl;
            break;
        }
        case 2: {
            double side;
            cout << "\nEnter side of the cube: ";
            cin >> side;
            cout << "Volume of Cube: " << calculateCubeVolume(side) << endl;
            break;
        }
        case 3: {
            double radius;
            cout << "\nEnter radius of the circle: ";
            cin >> radius;
            cout << "Area of Circle: " << calculateArea(radius) << endl;
            cout << "Circumference of Circle: " << calculateCircumference(radius) << endl;
            break;
        }
        case 4: {
            double length, width;
            cout << "\nEnter length of rectangle: ";
            cin >> length;
            cout << "Enter width of rectangle: ";
            cin >> width;
            cout << "Area of Rectangle: " << calculateRectangleArea(length, width) << endl;
            cout << "Perimeter of Rectangle: " << calculateRectanglePerimeter(length, width) << endl;
            break;
        }
        case 5: {
            int a, b;
            cout << "\nEnter starting number (a): ";
            cin >> a;
            cout << "Enter ending number (b): ";
            cin >> b;
            cout << "\nResult:\n";
            for (int n = a; n <= b; n++) {
                string word = numberToWord(n);
                cout << word << endl;
            }
            break;
        }
        default:
            cout << "Invalid choice!" << endl;
    }

    return 0;
}