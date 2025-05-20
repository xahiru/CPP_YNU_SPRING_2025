#include <iostream>
using namespace std;

// Define the structure
struct Area {
    int side; // for square
    int len;  // for rectangle
    int wid;  // for rectangle
};

// Function to calculate and display areas
void find_area(int side, int len, int wid) {
    // Create structure instance and assign values
    Area a;
    a.side = side;
    a.len = len;
    a.wid = wid;
    
    // Calculate areas
    int square_area = a.side * a.side;
    int rectangle_area = a.len * a.wid;
    
    // Output results
    cout << square_area << " " << rectangle_area << endl;
}

int main() {
    // Test case from example
    find_area(25, 40, 60); // Output: 625 2400
    
    // Additional test cases
    find_area(10, 20, 30); // Output: 100 600
    find_area(5, 15, 25);  // Output: 25 375
    
    return 0;
}