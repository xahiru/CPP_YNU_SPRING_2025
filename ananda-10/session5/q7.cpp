#include <iostream>
using namespace std;

int main() {
    int num, count = 0, max = INT_MIN, min = INT_MAX, sum = 0;

    while (true) {
        cout << "Enter a positive integer (-1 to terminate): ";
        cin >> num;
        if (num == -1) break;
        if (num > 0) {
            count++;
            sum += num;
            if (num > max) max = num;
            if (num < min) min = num;
        }
    }

    if (count > 0) {
        cout << "Your input is for termination. Here is the result below:\n";
        cout << "Number of positive integers is: " << count << endl;
        cout << "The maximum value is: " << max << endl;
        cout << "The minimum value is: " << min << endl;
        cout << "The average is: " << static_cast<double>(sum) / count << endl;
    } else {
        cout << "No positive integers were entered." << endl;
    }
    return 0;
}
