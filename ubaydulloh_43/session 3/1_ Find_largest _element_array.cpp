#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<int> arr = {5, 4, 9, 12};
    int largest = arr[0];

    for (int num : arr) {
        if (num > largest) {
            largest = num;
        }
    }
    cout << "The largest integer is: " << largest << endl;
    return 0;
}