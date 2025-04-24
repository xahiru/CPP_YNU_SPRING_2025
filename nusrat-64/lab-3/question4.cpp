#include <iostream>
using namespace std;

int main() {
    int arr[] = {0, 1, 0, 0, 1, 1, 1, 0, 1, 0};
    int size = 10;
    int count0 = 0;

    for (int i = 0; i < size; i++) {
        if (arr[i] == 0) {
            count0++;
        }
    }

    for (int i = 0; i < count0; i++) {
        arr[i] = 0;
    }

    for (int i = count0; i < size; i++) {
        arr[i] = 1;
    }

    cout << "Original array: 0 1 0 0 1 1 1 0 1 0" << endl;
    cout << "Array after divided: ";
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }

    return 0;
}