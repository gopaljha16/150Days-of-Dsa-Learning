#include <iostream>
using namespace std;

int main()
{
    int arr[5] = {1, 2, 3, 4, 5};
    //Decrement
    // int *ptr = arr+4;
    // Increment
    int *ptr = arr;
    // prints all the value

    // we can print this like this also we can get the value..
    // for(int i=0 ; i<5 ; i++){
    //     // cout<<ptr[i]<<endl; // it can we written like that
    //     cout<<*(ptr+i)<<endl;  // like this also it will print the value..
    // }

    // print all the address
    //  for(int i =0; i<5; i++){
    //     cout<<ptr+i<<endl;
    //  }

    // arithemetic operation  ptr++ , ptr--
    // we can use the increment operation
    // prints all the values
    // for(int i= 0 ;i<5 ; i++){
    //     cout<<*ptr<<endl;
    //     ptr++;
    // }

    // for (int i = 0; i < 8; i++)
    // {
    //     cout << *ptr << endl;
    //     ptr++;
    // } // it will access the location if it is outside the boundray then it will give any wrong answer and its an not good habit..
      // output : 1
    // 2 3 4 5 5 6422284 4200992

    // decrement
    //  for(int i=4 ;i>=0 ; i--){
    //      cout<<*ptr<<endl;
    //      ptr--;
    //  } 
     //printed this value when we take ptr = arr+4 then decrement it.. 

    //  Printing specific section by addtion.
    // Addition 
     ptr = arr+3;
     cout<<*ptr<<endl;

    //decrement 
    ptr = arr-2;
    cout<<*ptr<<endl;
}