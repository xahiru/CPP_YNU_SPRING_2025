#include <iostream>
#include <limits>
using namespace std;

int main() {
    int num, count = 0, maxVal = numeric_limits<int>::min(), minVal = numeric_limits<int>::max();
    double sum = 0;

    while (true) {
        cout << "Enter a positive integer (-1 to terminate): ";
        cin >> num;
        if (num == -1) break;

        count++;
        sum += num;
        if (num > maxVal) maxVal = num;
        if (num < minVal) minVal = num;
    }

    cout << "Number of positive integers is: " << count << endl;
    cout << "The maximum value is: " << maxVal << endl;
    cout << "The minimum value is: " << minVal << endl;
    cout << "The average is: " << (count > 0 ? sum / count : 0) << endl;
    return 0;
}