#include <iostream>
using namespace std;

int i[5] = {0, 2, 4, 6, 8};
int* p;

void foo() {
    cout << *p << endl; // Print the value pointed by p
    ++(*p);             // Increment the value at p
    ++p;                // Move the pointer to the next element
}

void bar() {
    for (int i = 0; i < 3; ++i) {
        foo(); // Call foo three times
    }
}

int main() {
    p = i; // Initialize p to point to the first element of i
    bar(); // Call bar
    cout << "Check Point 1" << endl;
    p = i; // Reset p to point to the first element of i
    foo(); // Call foo again
    cout << "Check Point 2" << endl;
    return 0;
}