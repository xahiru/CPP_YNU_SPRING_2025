#include <iostream>
#include <cmath> 
using namespace std;

int main() {

    double arr[] = {5, 4, 9, 12.8};
    int n = sizeof(arr) / sizeof(arr[0]);

    int largest = static_cast<int>(arr[0]);


    for (int i = 1; i < n; i++) {
        int current = static_cast<int>(arr[i]);
        if (current > largest) {
            largest = current;
        }
    }

    cout << "The largest integer is: " << largest << endl;
    return 0;
}
