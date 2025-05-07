#include <iostream>
#include <string>

int main() {
    // Dynamically allocate an integer
    int* pInt = new int;
    *pInt = 42;

    // Dynamically allocate a character
    char* pChar = new char;
    *pChar = 'A';

    // Dynamically allocate a string
    std::string* pString = new std::string;
    *pString = "Dynamic allocation!";

    // Print the values
    std::cout << "Integer value: " << *pInt << std::endl;
    std::cout << "Character value: " << *pChar << std::endl;
    std::cout << "String value: " << *pString << std::endl;

    // Free the allocated memory
    delete pInt;
    delete pChar;
    delete pString;

    return 0;
}
