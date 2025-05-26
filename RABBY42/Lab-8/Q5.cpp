#include <iostream>
using namespace std;

struct Area { int side, len, wid; };

void find_area(int s, int l, int w) {
    cout << s*s << " " << l*w;
}

int main() {
    int s, l, w; cin >> s >> l >> w;
    find_area(s, l, w);
}