#include <iostream>
#include <climits>
#include <iomanip>
using namespace std;

int main() {
    int num, count = 0, max = INT_MIN, min = INT_MAX;
    double sum = 0;
    
    cout << "Enter positive integers (-1 to terminate):\n";
    while (true) {
        cin >> num;
        if (num == -1) break;
        if (num > 0) {
            count++;
            sum += num;
            if (num > max) max = num;
            if (num < min) min = num;
        } else {
            cout << "Please enter positive integers only. Try again.\n";
        }
    }
    
    if (count > 0) {
        cout << "Number of positive integers is: " << count << endl;
        cout << "The maximum value is: " << max << endl;
        cout << "The minimum value is: " << min << endl;
        cout << "The average is " << fixed << setprecision(2) << sum/count << endl;
    } else {
        cout << "No positive integers were entered.\n";
    }
    return 0;
}