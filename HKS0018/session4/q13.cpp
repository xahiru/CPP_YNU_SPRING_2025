#include <iostream>
using namespace std;

int main() {
    int arr[] = {10, 22, 45, 11};
    int n = sizeof(arr) / sizeof(arr[0]); // Calculate number of elements
    double sum = 0;

    // Calculate sum of all elements
    for (int i = 0; i < n; i++) {
        sum += arr[i];
    }

    // Calculate average
    double average = sum / n;
    
    cout << "Average = " << average << endl;

    return 0;
}