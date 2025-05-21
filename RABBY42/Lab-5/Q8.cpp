#include <iostream>
#include <iomanip>
using namespace std;

int main() {
    int num, count = 0, sum = 0, max_val = 0, min_val = 0;
    bool first = true;
    while (true) {
        cin >> num;
        if (num == -1) break;
        if (num <= 0) continue;
        if (first) {
            max_val = min_val = num;
            first = false;
        } else {
            if (num > max_val) max_val = num;
            if (num < min_val) min_val = num;
        }
        sum += num;
        count++;
    }
    cout << "Number of positive integers is: " << count << endl;
    if (count > 0) {
        cout << "The maximum value is: " << max_val << endl;
        cout << "The minimum value is: " << min_val << endl;
        cout << fixed << setprecision(2) << "The average is " << static_cast<double>(sum)/count << endl;
    }
    return 0;
}