#include <iostream>

using namespace std;

bool isPalindrome(int number) {
    int originalNumber = number; // Store the original number
    int reversedNumber = 0; // Variable to store the reversed number

    // Reverse the number
    while (number > 0) {
        int digit = number % 10; // Get the last digit
        reversedNumber = reversedNumber * 10 + digit; // Build the reversed number
        number /= 10; // Remove the last digit
    }

    // Check if the original number is equal to the reversed number
    return originalNumber == reversedNumber;
}

int main() {
    int number;

    // Input number
    cout << "Enter a number to check if it is a palindrome: ";
    cin >> number;

    // Check if the number is a palindrome
    if (isPalindrome(number)) {
        cout << number << " is a palindrome number." << endl;
    } else {
        cout << number << " is not a palindrome number." << endl;
    }

    return 0;
}