#include <iostream>
using namespace std;

int main() {
    const char* str = "A string.";
    cout << str[0] << " " << *str << " " << str[3] << endl;
    str += 2;
    cout << *str << " " << str[1] << " " << str[4] << endl;
    return 0;
}
