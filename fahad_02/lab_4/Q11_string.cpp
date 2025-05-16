#include <iostream>
#include <string>

int main() {
    std::string str = "A string.";
    const char *ptr = str.c_str(); 
    std::cout << str[0] << " " << *ptr << " " << 't' << std::endl;
    
    ptr += 2;
    
    std::cout << *ptr << " " << 'r' << " " << 'g' << std::endl;
    
    return 0;
}