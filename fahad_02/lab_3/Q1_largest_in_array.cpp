#include<iostream>
using namespace std;

int main(){
    float arr[4] = {5,4,89,12.8};
    int n = sizeof(arr)/sizeof(arr[0]);
    int max = 0;

    for(int i=0; i<n; i++){
        if(max<arr[i]){
            max = arr[i];
        }
    }

    cout<<"The largest integer is: "<<max<<endl;
}