#include <iostream>
#include <limits>  

using namespace std;

int main() {
    int num;  
    int count = 0;  
    int max = numeric_limits<int>::min();  
    int min = numeric_limits<int>::max();  
    double sum = 0;  

    while (true) {
        cout << "Enter a positive integer (or -1 to terminate): ";
        cin >> num;

        if (num == -1) {
            break;  
        }

        if (num > 0) {
            count++;  
            sum += num; 

            if (num > max) {
                max = num;
            }

            if (num < min) {
                min = num;
            }
        } else {
            cout << "Please enter a positive integer!" << endl;  
        }
    }

    if (count > 0) {
        double average = sum / count;  
        cout << "\nYour input is for termination. Here is the result below:\n";
        cout << "Number of positive integers is: " << count << endl;
        cout << "The maximum value is: " << max << endl;
        cout << "The minimum value is: " << min << endl;
        cout << "The average is: " << average << endl;
    } else {
        cout << "No valid positive integers were entered." << endl; 
    }

    return 0;
}