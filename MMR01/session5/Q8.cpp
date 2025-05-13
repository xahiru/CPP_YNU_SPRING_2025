#include <iostream>
#include <iomanip>
#include <climits>

using namespace std;

int main() {
    int number;
    int count = 0;
    int sum = 0;
    int maximum = INT_MIN; // Initialize to smallest possible integer
    int minimum = INT_MAX; // Initialize to largest possible integer
    
    cout << "Enter positive integers (enter -1 to terminate):" << endl;
    
    while (true) {
        cin >> number;
        
        // Check for termination signal
        if (number == -1) {
            break;
        }
        
        // Validate input is positive
        if (number <= 0) {
            cout << "Please enter only positive integers. Try again." << endl;
            continue;
        }
        
        // Update statistics
        count++;
        sum += number;
        if (number > maximum) {
            maximum = number;
        }
        if (number < minimum) {
            minimum = number;
        }
    }
    
    // Display results
    cout << "\nYour input is for termination. Here is the result below:" << endl;
    cout << "Number of positive integers is: " << count << endl;
    
    if (count > 0) {
        cout << "The maximum value is: " << maximum << endl;
        cout << "The minimum value is: " << minimum << endl;
        cout << fixed << setprecision(2);
        cout << "The average is " << static_cast<double>(sum) / count << endl;
    } else {
        cout << "No positive integers were entered." << endl;
    }
    
    return 0;
}