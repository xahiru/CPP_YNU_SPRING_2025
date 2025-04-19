#include <iostream>
using namespace std;

int main() {
    int arr[4] = {5, 4, 9, 12};
    int largest = arr[0];

    for (int i = 1; i < 4; i++) {
        if (arr[i] > largest) {
            largest = arr[i];
        }
    }

    cout << "---------------------------------------" << endl;
    cout << "The largest integer is: " << largest << endl;

    return 0;
}