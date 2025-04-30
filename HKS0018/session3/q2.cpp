#include<iostream>

using namespace std;

int main (){
    int a=0;
     int arr[]={7 , 12, 9 ,15, 19 ,32,56,70};
     int size = sizeof(arr)/sizeof(arr[0]);
     for ( int i= 0; i <size -1 ; i++){

        for (int j = 0; j < size - i - 1; j++)
     {
        if (arr[j] > arr[j + 1]) {
            int temp = arr[j];
            arr[j] = arr[j + 1];
            arr[j + 1] = temp;
        } 
     }
    }
    
    for (int i = size - 1; i >= size - 3; i--) {
        cout << arr[i] << endl;
    }

     
     

    


     return 0;
}
