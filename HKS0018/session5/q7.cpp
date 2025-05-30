#include <iostream>
#include <iomanip>
#include <climits>

using namespace std;

int main() {
    int num;
    int count = 0;
    int max = INT_MIN; 
    int min = INT_MAX; 
    int sum = 0;
    

    cout << "Enter positive integers (enter -1 to terminate):" << endl;
    
    while (true) {
        cin >> num;
        if (num == -1) {
            break;
        }
        // Validate if input is positive
        if (num <= 0) {
            cout << "Please enter only positive integers. Try again." << endl;
            continue;
        }
        
        count++;
        sum += num;
        
        if (num > max) {
            max = num;
        }
        
        if (num < min) {
            min = num;
        }
    }

    cout << "\nYour input is for termination. Here is the result below:" << endl;
    cout << "Number of positive integers is: " << count << endl;
    
    if (count > 0) {
        cout << "The maximum value is: " << max << endl;
        cout << "The minimum value is: " << min << endl;
        double average = static_cast<double>(sum) / count;
        cout << fixed << setprecision(2);
        cout << "The average is " << average << endl;
    } else {
        cout << "No positive integers were entered." << endl;
    }
    
    return 0;
    
}
