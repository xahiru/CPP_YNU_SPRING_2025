#include <iostream>
using namespace std;

int main() {
    int n;                          
    long long factorial = 1;        //use long long to handle larger numbers

    cout << "Enter a positive integer: ";
    cin >> n;                       //take user input

    if (n < 0) {                    //check for negative input
        cout << "Error! Factorial of a negative number doesn't exist.";
    } else {                        //for non-negative numbers
        for(int i = 1; i <= n; ++i) { //loop from 1 to n
            factorial *= i;          //multiply factorial by each number
        }
        cout << "Factorial of " << n << " = " << factorial;
    }

    return 0;
}