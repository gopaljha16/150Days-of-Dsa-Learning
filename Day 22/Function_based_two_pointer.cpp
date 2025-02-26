#include <iostream>
using namespace std;

// using double pointer and changing the value..
 void fun(int  **p1){
    *p1 = *p1 +1;
 }

int main(){

    int n = 10;
    int *p = &n;
    int **ptr = &p;
    fun(ptr);
    cout<<ptr;  // in this we are using pointer taking address and incrementing it by 1 so example address will be 100+1 *4 is data type so it will go to 104 like that we are doing by using double pointer
}