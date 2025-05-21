#include <iostream>
#include <limits>
using namespace std;

int main() {
    int number;
    int count = 0;
    int max = numeric_limits<int>::min(); 
    int min = numeric_limits<int>::max(); 
    double sum = 0.0;

    cout << "Enter positive integers (or -1 to terminate):" << endl;

    while (true) {
        cin >> number;

        if (number == -1) {
            break; 
        }

        if (number <= 0) {
            cout << "Invalid input. Please enter a positive integer or -1 to terminate." << endl;
            continue; 
        }

        count++;
        sum += number;
        if (number > max) {
            max = number;
        }
        if (number < min) {
            min = number;
        }
    }

    if (count == 0) {
        cout << "No positive integers were entered." << endl;
    } else {
        cout << "Your input is for termination. Here is the result below:" << endl;
        cout << "Number of positive integers is: " << count << endl;
        cout << "The maximum value is: " << max << endl;
        cout << "The minimum value is: " << min << endl;
        cout << "The average is: " << (sum / count) << endl;
    }

    return 0;
}
