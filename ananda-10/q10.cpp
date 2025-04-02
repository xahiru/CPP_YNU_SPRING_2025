#include <iostream>
using namespace std;

int main() {
    int number;
    cout << "Enter a number: ";
    cin >> number;

    bool isPrime = (number > 1);
    for (int i = 2; i * i <= number && isPrime; i++) {
        if (number % i == 0) {
            isPrime = false;
        }
    }
    cout << number << (isPrime ? " is a prime number." : " is not a prime number.") << endl;

    return 0;
}
