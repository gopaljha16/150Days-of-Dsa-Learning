#include<iostream>
using namespace std;

int main(){

    int a = 10;
    //print the address of the a 
    //  by using '&'ampercent we can get the address of the varibale
    cout<<&a<<endl;
    // by using pointer we can print address
    int *ptr = &a;
    cout<<ptr<<endl;  // 0x61ff08 hexa decimal address

    // float value address printing by using pointer
    float b = 1.5;
    float *ptr1 = &b;
    cout<<ptr1<<endl;  // output:- 0x61ff00

    // pointer size by sizeof()
    cout<<sizeof(ptr)<<endl; // 4byte size
// For example, on a 32-bit system, the pointer size is typically 4 bytes (32 bits), allowing it to address up to 4 GB of memory, while on a 64-bit system, the pointer size is 8 bytes (64
    cout<<sizeof(ptr1)<<endl; // 4byte size


    // Print value of that addres
    int c = 30;
    int *ptr2 = &c;
    cout<<ptr2<<endl; // this print address of the c
    cout<<*ptr2<<endl; // this print that c addres value
// by using same pointer we can assign new address and prints the value
    int d = 50;
    ptr2 = &d;
    cout<<ptr2<<endl;  // address of d
    cout<<*ptr2<<endl;  // print the value of d address
    d = 90;
    cout<<*ptr2<<endl; // output will be 90 because it is updated and ptr is pointing the value of b

}