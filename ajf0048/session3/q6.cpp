#include <iostream>
using namespace std;

int main() {
    int arr[] = {1, 2, 3, 5, 5, 7, 8, 8, 9, 9, 2};
    int size = sizeof(arr) / sizeof(arr[0]);
    int count[100] = {0};

    for (int i = 0; i < size; i++) {
        count[arr[i]]++;
    }

    cout << "Repeating elements: ";
    for (int i = 0; i < 100; i++) {
        if (count[i] > 1) {
            cout << i << " ";
        }
    }
    cout << endl;
    return 0;
}
