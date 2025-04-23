#include <iostream>
using namespace std;

int sum_from_to(int first, int last) {
    int sum = 0;
    for (int i = first; i <= last; ++i) {
        summ += i;
    }
    return sum;
}

int main() {
    int a, b;
    cin >> a >> b;
    cout << "Sum is: " << sum_from_to(a, b) << endl;
    return 0;
}