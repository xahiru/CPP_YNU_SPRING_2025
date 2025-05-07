#include <iostream>

using namespace std;

int fibonacci(int n) {
    if (n <= 1)  // Base case: F(0)=0, F(1)=1
        return n;
    return fibonacci(n - 1) + fibonacci(n - 2);  // Recursive case
}

int main() {
    int n;
    
    cout << "Input a number: ";
    cin >> n;

    if (n < 0) {
        cout << "Fibonacci is not defined for negative numbers." << endl;
    } else {
        cout << "The " << n << "th Fibonacci number is: " << fibonacci(n) << endl;
    }

    return 0;
}