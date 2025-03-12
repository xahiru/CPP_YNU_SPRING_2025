#include <iostream>
using namespace std;

int main() {
    int n = 44;
  
    // to check if n is positive
    if (n > 0) {

        // to check if the positive n is even or odd
        if (n % 2 == 0) {
            cout << "positive and even number";
        }
        else {
            cout << "positive and odd number";
        }
    }
    // to check if the n is 0
    else if (n == 0) {
        cout << "the number is zero";
    }
    // to check if the n is negative
    else {
        cout << "the number is negative";
    }
    return 0;
}
