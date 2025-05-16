#include <iostream>
#include <array> // For std::array (optional)

using namespace std;

int main() {
    // Create an array (using traditional C-style array)
    int arr[] = {1, 2, 3};
    const size_t size = sizeof(arr) / sizeof(arr[0]); // Calculate array size

    // Print original array using range-based for loop
    cout << "Array: [";
    bool first = true;
    for (const auto& num : arr) {
        if (!first) cout << ", ";
        cout << num;
        first = false;
    }
    cout << "]" << endl;

    // Double each element using references
    for (auto& num : arr) { // Note: non-const reference
        num *= 2;
    }

    // Print doubled array using range-based for loop
    cout << "Doubled Array: [";
    first = true;
    for (const auto& num : arr) {
        if (!first) cout << ", ";
        cout << num;
        first = false;
    }
    cout << "]" << endl;

    return 0;
}