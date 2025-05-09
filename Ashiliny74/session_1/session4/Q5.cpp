#include <iostream>
#include <string>

int main() {
    // Dynamically allocate an integer
    int *intPtr = new int; // Allocate memory for an integer
    *intPtr = 42;          // Assign a value to the allocated integer

    // Dynamically allocate a character
    char *charPtr = new char; // Allocate memory for a character
    *charPtr = 'A';           // Assign a value to the allocated character

    // Dynamically allocate a string
    std::string *strPtr = new std::string; // Allocate memory for a string
    *strPtr = "Hello, World!";              // Assign a value to the allocated string

    // Output the values
    std::cout << "Dynamically allocated integer: " << *intPtr << std::endl;
    std::cout << "Dynamically allocated character: " << *charPtr << std::endl;
    std::cout << "Dynamically allocated string: " << *strPtr << std::endl;

    // Deallocate the memory
    delete intPtr;   // Free the memory allocated for the integer
    delete charPtr;  // Free the memory allocated for the character
    delete strPtr;   // Free the memory allocated for the string

    return 0;
}