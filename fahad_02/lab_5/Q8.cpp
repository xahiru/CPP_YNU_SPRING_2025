#include <iostream>
#include <limits>   // For INT_MAX and INT_MIN
#include <iomanip>  // For fixed and setprecision

using namespace std;

int main() {
    int num;
    int count = 0;
    int sum = 0;
    int maxVal = numeric_limits<int>::min();
    int minVal = numeric_limits<int>::max();

    cout << "Enter positive integers one by one (enter -1 to terminate):\n";

    while (true) {
        cout << "Enter a number: ";
        cin >> num;

        if (num == -1) {
            break;
        }

        if (num <= 0) {
            cout << "Only positive integers are accepted. Try again.\n";
            continue;
        }

        count++;
        sum += num;

        if (num > maxVal) maxVal = num;
        if (num < minVal) minVal = num;
    }

    cout << "\nYour input is for termination. Here is the result below:\n";

    if (count == 0) {
        cout << "No valid positive integers were entered.\n";
    } else {
        double average = static_cast<double>(sum) / count;

        cout << "Number of positive integers is: " << count << endl;
        cout << "The maximum value is: " << maxVal << endl;
        cout << "The minimum value is: " << minVal << endl;
        cout << fixed << setprecision(2);
        cout << "The average is " << average << endl;
    }

    return 0;
}
