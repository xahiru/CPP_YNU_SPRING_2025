#include <iostream>

using namespace std;

struct Area {
    int side;
    int len;
    int wid;
};

void find_area(int side, int len, int wid) {
    int square_area = side * side;
    int rectangle_area = len * wid;
    cout << square_area << " " << rectangle_area << endl;
}

int main() {
    Area a;
    a.side = 25;
    a.len = 40;
    a.wid = 60;


    find_area(a.side, a.len, a.wid);

    return 0;
    
}
