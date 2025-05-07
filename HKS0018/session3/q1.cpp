#include<iostream>

using namespace std;

int main(){

    int num[]={5,4,9,12,8};

    int largest=num[0];
    int size = sizeof(num)/sizeof(num[0]);


    for (int i = 1; i < size; i++) {
        if (num[i] > largest) {
            largest = num[i];
        }
    }


    cout<<largest<<endl;







    return 0;
}