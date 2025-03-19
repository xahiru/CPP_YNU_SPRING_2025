#include <iostream>
using namespace std;


int main()
{

    // Defining a lambda
    auto res = [](int x) {
        return x + x;
    };
    cout << res(5);
    return 0;
}