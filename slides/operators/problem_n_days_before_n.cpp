// #include <bits/stdc++.h>
#include <iostream>

using namespace std;

// Deleting element while you go

int main() {
    int d = 0;  // The current day (0 = Sunday)
    int n = 9;  // Days to go back

    // Step 1: Calculate the cyclic range of N
    int x = n % 7;

    // Step 2: Subtract the value from D
    int ans = d - x;

    // Step 3: Handle negative results
    if (ans >= 0)
        cout << ans;
    else
        cout << ans + 7;

    return 0;
}