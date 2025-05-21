#include <iostream>
#include <vector>
#include <set>

using namespace std;

void printUniqueElements(const vector<int>& arr) {

    set<int> uniqueElements(arr.begin(), arr.end());

    cout << "Unique elements of the said array: ";
    for (const int& num : uniqueElements) {
        cout << num << " ";
    }
    cout << endl;
}

int main() {

    vector<int> arr = {1, 5, 7, 5, 8, 9, 11, 11, 2, 5, 6};

    cout << "Original array: ";
    for (const int& num : arr) {
        cout << num << " ";
    }
    cout << endl;

    printUniqueElements(arr);

    return 0;
}