#include <iostream>
using namespace std;

// void increment(int n){
//     n++;
// }


void increment(int  *p){
    *p= *p+1;  // like this it will increment we have sended the pointer with the address and it will take the value and increment the value in the num address and to 1 and it will print 11.. output
}

int main(){
    int num = 10;
    // increment(num);
    cout<<num<<endl;  // so in this without using pointer we are doing the changes the value increment it will not possible becuase the n will be created then num value will go to the n variable and it will change the n value 10 to hundered

    // by using pointer first we have to pass to the pointer the exact address (&)
     increment(&num);
     cout<<num<<endl;
}