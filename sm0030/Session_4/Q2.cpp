#include <iostream>

void updateVar(int *a) {
    *a = *a + 10;
}

int main() {
    int myVar = 5;
    int *ptr = &myVar;

    std::cout << "Before updateVar: myVar = " << myVar << std::endl;

    updateVar(ptr);

    std::cout << "After updateVar: myVar = " << myVar << std::endl;

    return 0;
}
