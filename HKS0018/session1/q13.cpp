#include <iostream>

using namespace std;

int main() {

    int n;
    long factorial = 1.0;

    cout << "Enter a positive integer: ";
    cin >> n;

    if (n < 0)
        cout << "Negative number can't be factorial!"; //an negatvie number won't be factorial if user input is is negative number it will be an error massege!
    else {
        for(int i = 1; i <= n; ++i) {
            factorial *= i;             //given function calculates the factorial number

        }
        cout << "Factorial of " << n << " = " << factorial<<endl;    
    }

    return 0;
}