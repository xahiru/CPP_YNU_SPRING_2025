#include <iostream>

using namespace std;

void fun(int x){
    
    if(x == 0)
    return ;
    else{
        cout << "YNU\n";
        fun(x - 1);
    }
   
}

int main() {

	fun(3);
	
	return 0;
}