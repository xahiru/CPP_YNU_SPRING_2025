#include <iostream>
#include <limits>

using namespace std;

int main() {
    int number;
    int count = 0;
    int sum = 0;
    int max = numeric_limits<int>::min();
    int min = numeric_limits<int>::max();

    cout << "Enter positive integers (-1 to terminate):" << endl;

    while (true) {
        cin >> number;

        if (number == -1) {
            break;
        }

        if (number > 0) {
            count++;
            sum += number;

            if (number > max) {
                max = number;
            }

            if (number < min) {
                min = number;
            }
        } else {
            cout << "Only positive integers are allowed. Try again." << endl;
        }
    }

    cout << "\nYour input is for termination. Here is the result below:" << endl;

    if (count > 0) {
        double average = static_cast<double>(sum) / count;
        cout << "Number of positive integers is: " << count << endl;
        cout << "The maximum value is: " << max << endl;
        cout << "The minimum value is: " << min << endl;
        cout << "The average is: " << fixed << setprecision(2) << average << endl;
    } else {
        cout << "No positive integers were entered." << endl;
    }

    return 0;
}
