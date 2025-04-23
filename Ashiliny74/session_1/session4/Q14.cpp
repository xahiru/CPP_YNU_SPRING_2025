#include <iostream>
using namespace std;

int main() {
    // Define and initialize the array
    int arr[] = {10, 11, 7, 8, 2, 9};
    int size = sizeof(arr) / sizeof(arr[0]); // Calculate the number of elements in the array
    int elementToSearch;
    bool found = false; // Flag to indicate if the element is found

    // Prompt the user to enter the element to be searched
    cout << "Element to be Searched: ";
    cin >> elementToSearch;

    // Perform linear search
    for (int i = 0; i < size; ++i) {
        if (arr[i] == elementToSearch) {
            cout << "Element " << elementToSearch << " found at index: " << i << endl;
            found = true; // Set the flag to true if the element is found
            break; // Exit the loop since the element is found
        }
    }

    // If the element was not found, print a message
    if (!found) {
        cout << elementToSearch << " not found in the arr[]" << endl;
    }

    return 0;
}