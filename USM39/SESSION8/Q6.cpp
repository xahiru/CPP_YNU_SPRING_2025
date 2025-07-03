#include <iostream>
using namespace std;

struct NODE {
    union {
        double data;
        struct NODE* left;
        struct NODE* right;
    };
    bool isLeaf; 
};

int main() {
    return 0;
}
