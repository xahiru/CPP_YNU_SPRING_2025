
#include <iostream>
#include <unordered_map>
using namespace std;

void findRepeatingElements(int arr[], int size) {
    unordered_map<int, int> freq;

    for (int i = 0; i < size; i++) {
        freq[arr[i]]++;
    }

    cout << "Repeating elements: ";
    for (auto it : freq) {
        if (it.second > 1)
            cout << it.first << " ";
    }
    cout << endl;
}

int main() {
    int arr[] = {1, 2, 3, 5, 5, 7, 8, 8, 9, 9, 2};
    int size = sizeof(arr) / sizeof(arr[0]);

    cout << "Original array: ";
    for (int i = 0; i < size; i++)
        cout << arr[i] << " ";
    cout << endl;

    findRepeatingElements(arr, size);

    return 0;
}
