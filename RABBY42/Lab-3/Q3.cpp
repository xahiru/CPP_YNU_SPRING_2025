#include <iostream>
#include <climits>

using namespace std;

int findSecondSmallest(int arr [], int size) {
    if (size < 2)
    {
        return INT_MAX;
    }

    int smallest = INT_MAX;
    int secondSmallest = INT_MAX;

    for (int  i = 0; i  < size; i++) {
        if (arr [i] < smallest) {
            secondSmallest = smallest;
            smallest = arr [i];
        }
        else if (arr [i] < secondSmallest && arr[i] != smallest) {
            secondSmallest = arr[i];
        }
    }
    return secondSmallest;
    
}

int main() {
    int arr[] = {5, 6, 7, 2, 3, 4, 12};
    int size = sizeof(arr) / sizeof(arr[0]);

    cout << "Original array: ";
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    int result = findSecondSmallest(arr, size);
    if (result != INT_MAX) {
        cout << "Second smallest number: " << result << endl;
    } else {
        cout << "NO second smallest element exists." << endl;
    }

    return 0;
}