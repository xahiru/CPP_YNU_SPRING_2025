#include <iostream>

using namespace std;

bool isPrime(int number) {
    // Handle special cases
    if (number <= 1) return false; // 0 and 1 are not prime numbers
    if (number <= 3) return true;  // 2 and 3 are prime numbers

    // Check for factors from 2 to the square root of the number
    for (int i = 2; i * i <= number; i++) {
        if (number % i == 0) {
            return false; // Found a factor, not a prime number
        }
    }
    return true; // No factors found, it's a prime number
}

int main() {
    int number;

    // Input number
    cout << "Enter a number to check if it is prime: ";
    cin >> number;

    // Check if the number is prime
    if (isPrime(number)) {
        cout << number << " is a prime number." << endl;
    } else {
        cout << number << " is not a prime number." << endl;
    }

    return 0;
}