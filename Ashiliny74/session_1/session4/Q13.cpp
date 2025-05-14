#include <iostream>
using namespace std;

int main() {
    // Define and initialize the array
    int arr[] = {10, 22, 45, 11};
    int size = sizeof(arr) / sizeof(arr[0]); // Calculate the number of elements in the array
    int sum = 0;

    // Calculate the sum of the elements
    for (int i = 0; i < size; ++i) {
        sum += arr[i];
    }

    // Calculate the average
    double average = static_cast<double>(sum) / size;

    // Print the average
    cout << "Average = " << average << endl;

    return 0;
}