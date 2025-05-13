#include <iostream>
#include <iomanip> 

using namespace std;

int main() {
    int n;
    
    cout << "Input the number upto: ";
    cin >> n;
    
    cout << "Multiplication table from 1 to " << n << endl;
    
    // Outer loop for rows (multiplication factors)
    for (int i = 1; i <= 10; i++) { // Standard multiplication table goes up to 10
        // Inner loop for columns (numbers 1 to n)
        for (int j = 1; j <= n; j++) {
            // Format each multiplication with setw for alignment
            cout << j << "x" << i << "=" << setw(2) << j * i << " ";
        }
        cout << endl; // New line after each row
    }
    
    return 0;
}