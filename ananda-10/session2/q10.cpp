#include <iostream>
using namespace std;

int sum_from_to(int first, int last) {
    int sum = 0;
    
    if (first > last) {
        swap(first, last);
    }

    for (int i = first; i <= last; i++) {
        sum += i;
    }

    return sum;
}

int main() {
    cout << sum_from_to(4, 7) << endl;    // Output: 22
    cout << sum_from_to(-3, 1) << endl;   // Output: -5
    cout << sum_from_to(7, 4) << endl;    // Output: 22
    cout << sum_from_to(9, 9) << endl;    // Output: 9

    return 0;
}
