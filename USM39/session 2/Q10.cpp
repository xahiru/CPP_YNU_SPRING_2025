#include <iostream>
using namespace std;

int sum_from_to(int first, int last) {
    int sum = 0;
    for (int i = first; i <= last; i++) {
        sum += i;
    }
    return sum;
}

int main() {
    int first, last;
    cout << "Enter first and last numbers: ";
    cin >> first >> last;
    cout << "Sum is: " << sum_from_to(first, last) << endl;
    return 0;
}