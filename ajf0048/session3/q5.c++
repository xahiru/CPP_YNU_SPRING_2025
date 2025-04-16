#include <iostream>
using namespace std;

int main() {
    int arr[] = {0, 1, 2, 2, 1, 1, 0, 0, 1};
    int size = sizeof(arr) / sizeof(arr[0]);
    int low = 0, mid = 0, high = size - 1;

    while (mid <= high) {
        switch (arr[mid]) {
            case 0:
                swap(arr[low++], arr[mid++]);
                break;
            case 1:
                mid++;
                break;
            case 2:
                swap(arr[mid], arr[high--]);
                break;
        }
    }

    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
    return 0;
}
