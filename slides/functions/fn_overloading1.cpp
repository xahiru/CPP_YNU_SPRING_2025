#include <iostream>
using namespace std;

// Function to find the maximum of two integers
int myMax(int x, int y) {
    return (x > y) ? x : y;  // Ternary operator to find the maximum
}

// Function to find the maximum of three integers
int myMax(int x, int y, int z) {
    return myMax(myMax(x, y), z);  // Compare maximum of x and y with z
}

int main() {
    int a = 10, b = 30, c = 5;

    // Call to the two-parameter version of myMax
    cout << myMax(a, b) << "\n";

    // Call to the three-parameter version of myMax
    cout << myMax(a, b, c) << "\n";

    return 0;
}