#include <iostream>
#include <climits>
#include <iomanip>
using namespace std;

int main() {
    int num, count = 0, max = INT_MIN, min = INT_MAX;
    double sum = 0;
    
    cout << "Enter positive integers (enter -1 to stop):\n";
    
    while (true) {
        cin >> num;
        if (num == -1) break;
        if (num > 0) {
            count++;
            sum += num;
            if (num > max) max = num;
            if (num < min) min = num;
        }
    }
    
    cout << fixed << setprecision(2);
    cout << "Your input is for termination. Here is the result below:\n";
    cout << "Number of positive integers is: " << count << endl;
    cout << "The maximum value is: " << max << endl;
    cout << "The minimum value is: " << min << endl;
    cout << "The average is " << (count > 0 ? sum/count : 0) << endl;
    
    return 0;
}
