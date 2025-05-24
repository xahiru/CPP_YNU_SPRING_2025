#include <iostream>
using namespace std;

bool isPrime(int number) {
    if (number <= 1) return false; // 0 and 1 are not prime numbers
    if (number == 2) return true;  // 2 is the only even prime number
    if (number % 2 == 0) return false; // Exclude even numbers greater than 2

    for (int i = 3; i * i <= number; i += 2) { // Check only odd numbers
        if (number % i == 0) {
            return false; // Found a divisor, not prime
        }
    }
    return true; // No divisors found, it's prime
}

int main() {
    int number;
    cout << "Number to Check = ";
    cin >> number;

    if (isPrime(number)) {
        cout << number << " is a prime number." << endl;
    } else {
        cout << number << " is not a prime number." << endl;
    }
    return 0;
}