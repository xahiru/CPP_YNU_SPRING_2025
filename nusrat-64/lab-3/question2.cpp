#include <iostream>
using namespace std;

int main() {
    int arr[] = {7, 12, 9, 15, 19, 32, 56, 70};
    int size = 8;

    int first = -1, second = -1, third = -1;

    for (int i = 0; i < size; i++) {
        if (arr[i] > first) {
            third = second;
            second = first;
            first = arr[i];
        }
        else if (arr[i] > second) {
            third = second;
            second = arr[i];
        }
        else if (arr[i] > third) {
            third = arr[i];
        }
    }

    cout << "Original array: ";
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    cout << "Three largest elements are: " << first << ", " << second << ", " << third << endl;

    return 0;
}