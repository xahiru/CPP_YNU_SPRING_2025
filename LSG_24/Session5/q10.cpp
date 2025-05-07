#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "Input the number of Letters (less than 26) in the Pyramid: ";
    cin >> n;
    
    for (int i = 0; i < n; i++) {
        // Increasing letters
        for (int j = 0; j <= i; j++) {
            cout << char('A' + j) << " ";
        }
        // Decreasing letters
        for (int j = i-1; j >= 0; j--) {
            cout << char('A' + j) << " ";
        }
        cout << endl;
    }
    return 0;
}