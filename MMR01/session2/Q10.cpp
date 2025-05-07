#include <iostream>
using namespace std;

int sum_from_to(int first, int last) {
    int sum = 0;

    if (first <= last) {
        for (int i = first; i <= last; ++i) {
            sum += i;
        }
    } else { // first > last
        for (int i = first; i >= last; --i) {
            sum += i;
        }
    }

    return sum;
}

int main() {
    // Test cases
    cout << sum_from_to(4, 7) << endl;   // Output: 22 (4+5+6+7)
    cout << sum_from_to(-3, 1) << endl;  // Output: -5 (-3 + -2 + -1 + 0 + 1)
    cout << sum_from_to(7, 4) << endl;   // Output: 22 (7+6+5+4)
    cout << sum_from_to(9, 9) << endl;   // Output: 9 (only 9)

    return 0;
}