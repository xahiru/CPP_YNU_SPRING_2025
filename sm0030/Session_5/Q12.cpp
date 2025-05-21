#include <iostream>

int main() {
    int n;
    std::cout << "Enter n: ";
    std::cin >> n;

    // Dynamically allocate an array to hold n integers
    int* squares = new int[n];

    // Fill the array with squares of the first n natural numbers
    for (int i = 0; i < n; ++i) {
        squares[i] = (i + 1) * (i + 1);
    }

    std::cout << "Squares:";
    // Print the elements of the dynamically allocated array
    for (int i = 0; i < n; ++i) {
        std::cout << " " << squares[i];
    }
    std::cout << std::endl;

    // Deallocate the dynamically allocated memory
    delete[] squares;
    squares = nullptr; // Good practice to set to nullptr after deletion

    return 0;
}