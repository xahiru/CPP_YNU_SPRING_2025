
#include <iostream>
#include <string>

int main() {
    int *intPtr = new int;
    *intPtr = 42;
    char *charPtr = new char;
    *charPtr = 'A';
    std::string *strPtr = new std::string;
    *strPtr = "Hello, World!";
    std::cout << "Dynamically allocated integer: " << *intPtr << std::endl;
    std::cout << "Dynamically allocated character: " << *charPtr << std::endl;
    std::cout << "Dynamically allocated string: " << *strPtr << std::endl;
    delete intPtr;
    delete charPtr;
    delete strPtr;

    return 0;
}