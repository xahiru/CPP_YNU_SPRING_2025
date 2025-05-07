#include <iostream>
using namespace std;

void findSmallerThanNeighbours(int arr[], int size) {
    cout << "Vector elements that are smaller than its adjacent neighbours:\n";
    for (int i = 1; i < size - 1; ++i) {
        if (arr[i] < arr[i - 1] && arr[i] < arr[i + 1]) {
            cout << arr[i] << "\n";
        }
    }
}

int main() {
    int arr[] = {1, 2, 5, 0, 3, 1, 7};
    int size = sizeof(arr) / sizeof(arr[0]);
    cout << "Original Vector elements:\n";
    for (int i = 0; i < size; ++i) {
        cout << arr[i] << " ";
    }
    cout << endl;
    findSmallerThanNeighbours(arr, size);
    return 0;
}