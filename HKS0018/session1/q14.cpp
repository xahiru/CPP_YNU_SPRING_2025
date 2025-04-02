#include <iostream>

using namespace std;

void printInvertedTriangle(int n) {

    for (int i = n; i > 0; --i) {
        for (int j = 0; j < n - i; ++j) {  //print spaces 
            cout << " ";
        }
        for (int k = 0; k < (2 * i - 1); ++k) { // print stars to create the inverted tringale 
            cout << "*";
        }
        cout << endl; // Move to next line
    }
}

int main() {
    int height;
    cout << "Enter a number: "; // this program takes user input to get the height or lenght of the triangle
    cin >> height;
    
    printInvertedTriangle(height);


    
    return 0; 
}
