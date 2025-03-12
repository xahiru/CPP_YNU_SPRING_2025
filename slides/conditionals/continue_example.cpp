// C++ program to use continue statement to continue the
// loop when i become 3

#include <iostream>
using namespace std;

int main()
{
    for (int i = 0; i < 5; i++) {
        // if i become 3 then skip the rest body of loop and
        // move next iteration
        if (i == 3) {
            continue;
        }
        cout << i << endl;
    }
    return 0;
}
