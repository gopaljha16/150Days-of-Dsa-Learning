#include <iostream>
using namespace std;

  void increment(int** &p){
    p = p+1;
 }


// changing the address by using reference pointer
int main(){
   int  n = 10;
   int *p = &n;
   int **ptr = &p;
   cout<<ptr<<endl;
   increment(ptr);
   cout<<ptr;
}// so in this code by using referece pointer we have changed the address move by +4 by increment by 1