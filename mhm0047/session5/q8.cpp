#include <iostream>
#include <iomanip>
#include <limits>
using namespace std;

int main() {
    int input;
    int totalNumbers = 0;
    int maximum = numeric_limits<int>::min();
    int minimum = numeric_limits<int>::max();
    double totalSum = 0;

    cout << "Enter positive integers (enter -1 to end):" << endl;

    while (true) {
        cin >> input;

        if (input == -1) {
            break;
        }

        if (input > 0) {
            totalNumbers++;
            totalSum += input;

            if (input > maximum) {
                maximum = input;
            }
            if (input < minimum) {
                minimum = input;
            }
        } else {
            cout << "Invalid input. Only positive integers are accepted. Try again." << endl;
        }
    }

    if (totalNumbers > 0) {
        double average = totalSum / totalNumbers;

        cout << "\nYour input is for termination. Here is the result below:" << endl;
        cout << "Number of positive integers is: " << totalNumbers << endl;
        cout << "The maximum value is: " << maximum << endl;
        cout << "The minimum value is: " << minimum << endl;
        cout << "The average is " << fixed << setprecision(2) << average << endl;
    } else {
        cout << "\nNo valid positive integers were entered." << endl;
    }

    return 0;
}
