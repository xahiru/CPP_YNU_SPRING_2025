#include<iostream>
using namespace std;

template<typename T>
T getMax(T arr[], int n) {
    T max = arr[0];
    for (int i = 1; i < n; i++)
        if (arr[i] > max)
            max = arr[i];
    return max;
}

int main() {
    int k = 2;
    if (k == 1) {
        int arr[] = {1, 8, 7, 56, 90};
        cout << getMax(arr, 5);
    } else {
        float arr[] = {1.1, 2.2, 0, 3.2, 2.7, 4.6, 5.0};
        cout << getMax(arr, 7);
    }
    return 0;
}
