#include <iostream>
#include <climits>
using namespace std;

int main() {

    int arr[] = {5, 6, 7, 2, 3, 4, 12};
    int n = sizeof(arr) / sizeof(arr[0]);

    int smallest = INT_MAX;
    int secondSmallest = INT_MAX;

    for (int i = 0; i < n; i++) {
        if (arr[i] < smallest) {
            secondSmallest = smallest; 
            smallest = arr[i];         
        } else if (arr[i] < secondSmallest && arr[i] != smallest) {
            secondSmallest = arr[i];  
        }
    }

    cout << "Original array: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    if (secondSmallest == INT_MAX) {
        cout << "There is no second smallest element." << endl;
    } else {
        cout << "Second smallest number: " << secondSmallest << endl;
    }

    return 0;
}