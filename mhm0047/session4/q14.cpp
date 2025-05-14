#include <iostream>
using namespace std;

void searchElement(int array[], int length, int element) {
    int position = -1;

    for (int index = 0; index < length; index++) {
        if (array[index] == element) {
            position = index;
            break;
        }
    }

    if (position != -1) {
        cout << element << " found at index " << position << endl;
    } else {
        cout << element << " not found in the array[]" << endl;
    }
}

int main() {
    int data[] = {10, 11, 7, 8, 2, 9};
    int size = sizeof(data) / sizeof(data[0]);
    int searchFor = 19;

    searchElement(data, size, searchFor);

    return 0;
}
