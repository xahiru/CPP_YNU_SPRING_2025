#include <iostream>
using namespace std;

int main() {
    int arr[] = {5, 6, 7, 2, 3, 4, 12};
    int size = 7;

    int smallest = arr[0];
    int secondSmallest = INT_MAX;

    for (int i = 1; i < size; i++) {
        if (arr[i] < smallest) {
            smallest = arr[i];
        }
    }

    for (int i = 0; i < size; i++) {
        if (arr[i] > smallest && arr[i] < secondSmallest) {
            secondSmallest = arr[i];
        }
    }

    cout << "Original array: ";
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    cout << "Second smallest number: " << secondSmallest << endl;

    return 0;
}