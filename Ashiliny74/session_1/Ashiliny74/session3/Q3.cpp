#include <iostream>
#include <limits>

using namespace std;

void findSecondSmallest(int arr[], int n) {
    if (n < 2) {
        cout << "Array must contain at least two elements." << endl;
        return;
    }

    int smallest = std::numeric_limits<int>::max();
    int secondSmallest = std::numeric_limits<int>::max();

    for (int i = 0; i < n; i++) {
        // Update smallest and second smallest accordingly
        if (arr[i] < smallest) {
            secondSmallest = smallest;
            smallest = arr[i];
        } else if (arr[i] < secondSmallest && arr[i] != smallest) {
            secondSmallest = arr[i];
        }
    }

    if (secondSmallest == std::numeric_limits<int>::max()) {
        cout << "There is no second smallest element." << endl;
    } else {
        cout << "Second smallest number: " << secondSmallest << endl;
    }
}

int main() {
    int arr[] = {5, 6, 7, 2, 3, 4, 12};
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << "Original array: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    findSecondSmallest(arr, n);

    return 0;
}