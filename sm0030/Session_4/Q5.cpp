#include <iostream>
#include <string>

int main() {
    
    int* intPtr = new int;
    *intPtr = 10;
    std::cout << "Dynamically allocated integer: " << *intPtr << std::endl;
    delete intPtr; 

    
    char* charPtr = new char;
    *charPtr = 'A';
    std::cout << "Dynamically allocated character: " << *charPtr << std::endl;
    delete charPtr;

    
    std::string* strPtr = new std::string;
    *strPtr = "Hello, Dynamic World!";
    std::cout << "Dynamically allocated string: " << *strPtr << std::endl;
    delete strPtr; 
    return 0;
}