#include <iostream>

using namespace std;

int main() {
    int n;
    
    cout << "Input number of terms: ";
    cin >> n;
    
    int sum = n * n;  // Sum = n²
    
    cout << "The Sum of odd Natural Numbers upto " << n << " terms: " << sum << endl;
    
    return 0;
}