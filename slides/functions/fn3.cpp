#include <iostream>
using namespace std;

void fun() {
    cout << "Fun() Called\n";
}

int main() {
    cout << "Before calling fun()\n";
    fun();
    fun();
    cout << "After calling fun()\n";
    return 0;
}