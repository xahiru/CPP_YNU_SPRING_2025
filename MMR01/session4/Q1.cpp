#include <iostream>
using namespace std;

int main() {
    int a;
    
    // Ask user input a value for a
    cout << "Enter a value for a: ";
    cin >> a;
    
    // Get the address of a
    int* ptr = &a;
    
    // Print the value of a
    cout << "Entered Value of a: " << *ptr << endl;
    
    return 0;
}