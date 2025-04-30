cpp
#include <iostream>
#include <vector>

using namespace std;

int sumOfArray(const vector<int>& arr, int index) {

    if (index == arr.size()) {
        return 0; 
    }

    return arr[index] + sumOfArray(arr, index + 1);
}

int main() {

    vector<int> arr = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    cout << "Array elements: ";
    for (int num : arr) {
        cout << num << " ";
    }
    cout << endl;

    int sum = sumOfArray(arr, 0);

    cout << "Sum of array elements using recursion: " << sum << endl;

    return 0;
}