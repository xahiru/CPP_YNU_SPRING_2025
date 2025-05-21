#include <iostream>
using namespace std;

struct Node {
    double data;
    union {
        struct Node *left;
        struct Node *right;
    };
};

int main() {
    // Example usage of the Node struct would go here.
    return 0;
}
