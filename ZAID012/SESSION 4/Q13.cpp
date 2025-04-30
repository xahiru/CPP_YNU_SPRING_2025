#include <iostream>
using namespace std;

int main() {
    int arr[] = {10, 22, 45, 11};
    int size = sizeof(arr) / sizeof(arr[0]);
    double sum = 0;

    for (int i = 0; i < size; ++i) {
        sum += arr[i];
    }
    cout << "Average = " << sum / size << endl;
    return 0;
}
