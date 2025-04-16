#include <iostream>
using namespace std;

int main() {
    int arr[] = {1, 5, 7, 5, 8, 9, 11, 12};
    int size = sizeof(arr) / sizeof(arr[0]);
    int targetSum = 12;
    int count = 0;

    cout << "Original array: ";
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }

    cout << "\nArray pairs whose sum equal to " << targetSum << ":\n";

    for (int i = 0; i < size; i++) {
        for (int j = i + 1; j < size; j++) {
            if (arr[i] + arr[j] == targetSum) {
                cout << arr[i] << "," << arr[j] << endl;
                count++;
            }
        }
    }

    cout << "Number of pairs whose sum equal to " << targetSum << ": " << count << endl;

    return 0;
}
