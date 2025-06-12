#include <iostream>
using namespace std;

struct NODE {
    bool isLeaf;
    union {
        double data;
        struct {
            NODE* left;
            NODE* right;
        } children;
    };
};

int main() {
    NODE leaf = {true, .data = 3.14};
    NODE internal = {false};
    internal.children.left = &leaf;
    internal.children.right = nullptr;
    return 0;
}