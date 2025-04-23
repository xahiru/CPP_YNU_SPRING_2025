#include<iostream>  
using namespace std;

int main(){
    int arr[10] = {0, 1, 0, 0, 1, 1, 1, 0, 1, 0};
    int n = sizeof(arr)/sizeof(arr[0]);
    int half = n/2;
    int arr0[half], arr1[half];
    int j=0,k=0;

    for(int i=0; i<n; i++){
        if(arr[i]==0){
            arr0[j] = arr[i];
            j++;
        }
        else if(arr[i]==1){
            arr1[k] = arr[i];
            k++;
        }
    }

    for(int i=0; i<half; i++){
        cout<<arr0[i];
    }
    for(int i=0; i<half; i++){
        cout<<arr1[i];
    }
    cout<<endl;
}