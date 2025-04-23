#include <iostream>
using namespace std;

int main() {
    int arr[] = {0, 1, 2, 2, 1, 1, 0, 0, 1};
    int size = 9;
    int count0 = 0, count1 = 0, count2 = 0;

    for (int i = 0; i < size; i++) {
        if (arr[i] == 0)
            count0++;
        else if (arr[i] == 1)
            count1++;
        else
            count2++;
    }

    int index = 0;
    for (int i = 0; i < count0; i++)
        arr[index++] = 0;
    for (int i = 0; i < count1; i++)
        arr[index++] = 1;
    for (int i = 0; i < count2; i++)
        arr[index++] = 2;

    cout << "Original array: 0 1 2 2 1 1 0 0 1" << endl;
    cout << "Array elements after rearranging: ";
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }

    return 0;
}