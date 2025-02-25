#include <iostream>
using namespace std;
// pass by pointer..
  void swapping(int *p1 , int *p2){
      int temp = *p1;
      *p1 = *p2;
      *p2 = temp;
  }


//   in this p1 and p2 has their own location and as well as the temp
int main(){
    int first = 10 , second = 20;
    swapping(&first , &second);
    cout<<"first :- "<<first<<"  , second :- "<<second; // like this we will swap the numbers using the pointers
}