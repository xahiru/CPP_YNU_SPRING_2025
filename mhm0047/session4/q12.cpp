#include <iostream>

int main() {
    int int_bytes = sizeof(int);
    int float_bytes = sizeof(float);
    int double_bytes = sizeof(double);
    int char_bytes = sizeof(char);

    std::cout << "Bytes used by int: " << int_bytes << std::endl;
    std::cout << "Bytes used by float: " << float_bytes << std::endl;
    std::cout << "Bytes used by double: " << double_bytes << std::endl;
    std::cout << "Bytes used by char: " << char_bytes << std::endl;

    return 0;
}
