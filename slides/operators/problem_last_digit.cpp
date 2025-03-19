#include <iostream>
// #include <cmath>
using namespace std;

int main() {
    int x = -235;  // Input number
    int ans = abs(x % 10);  // Find the last digit using modulus and convert to positive if needed

    cout << ans <<endl;  // Output the last digit
    return 0;
}