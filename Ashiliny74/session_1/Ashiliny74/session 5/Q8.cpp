#include <iostream>
#include <limits>

using namespace std;

int main() {
    int input;
    int count = 0;
    int max = numeric_limits<int>::min(); // Start with the smallest possible integer
    int min = numeric_limits<int>::max(); // Start with the largest possible integer
    int total = 0;

    cout << "Enter positive integers (enter -1 to terminate):" << endl;

    while (true) {
        cin >> input;
        
        if (input == -1) {
            break; // Termination signal
        }

        // Check for positive integer
        if (input > 0) {
            count++;
            total += input;

            if (input > max) {
                max = input;
            }
            if (input < min) {
                min = input;
            }
        } else {
            cout << "Please enter a positive integer." << endl;
        }
    }

    // Check if any positive integers were processed
    if (count > 0) {
        double average = static_cast<double>(total) / count;
        cout << "\nYour input is for termination. Here is the result below:\n";
        cout << "Number of positive integers is: " << count << endl;
        cout << "The maximum value is: " << max << endl;
        cout << "The minimum value is: " << min << endl;
        cout << "The average is: " << average << endl;
    } else {
        cout << "No positive integers were entered." << endl;
    }

    return 0;
}