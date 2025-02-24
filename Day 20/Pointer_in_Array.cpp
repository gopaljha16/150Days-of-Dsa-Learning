#include <iostream>
using namespace std;

int main(){

    int arr[5] = {11,10,9,2,1};
    // way to print the address
    // cout<<arr+0<<endl;// by using this also we can print the arrays first index address
    // cout<<arr<<endl;  // same
    // cout<<arr+1<<endl;
    // by using arr+1 2 ,3,4,5 like this we can add
    // int *ptr = &arr[0];
    // /cout<<ptr<<endl;
    //value printing
    // cout<<*ptr<<endl;

    //pointers in array 
    // printing all array address
    for(int i = 0 ;i<5 ; i++){
       cout<<arr+i<<endl;
    }

    // if we want to print their address value
    for(int i = 0 ; i<5 ; i++){
        cout<<*(arr+i)<<endl;
    }

    // value 
    cout<<arr[0];
}