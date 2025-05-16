#include <iostream>
#include <vector>

using namespace std;

// Recursive function to calculate the sum of array elements
int sumArray(const vector<int>& arr, int n) {
    // Base case: if the array size is 0, return 0
    if (n <= 0) {
        return 0;
    }
    // Recursive case: return the last element plus the sum of the rest
    return arr[n - 1] + sumArray(arr, n - 1);
}

int main() {
    // Sample array
    vector<int> arr = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    // Print the array elements
    cout << "Array elements:\n";
    for (int num : arr) {
        cout << num << " ";
    }
    cout << endl;

    // Calculate the sum using recursion
    int sum = sumArray(arr, arr.size());

    // Print the result
    cout << "Sum of array elements using recursion: " << sum << endl;

    return 0;
}