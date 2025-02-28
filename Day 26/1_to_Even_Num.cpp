#include <iostream>
using namespace std;

//   void printEven(int num , int n){

//     //base condition
//     if(num>n)
//     return;

//     cout<<num<<" ";
//     printEven(num+2 , n);
//   }

//   void printEven(int num , int n){

//     //base condition
//     if(num==n)
//     return;

//     cout<<num<<" ";
//     printEven(num+2 , n);
//   }

// reverse order
 void printEven(int n){
     
    //base condition
    if(n==2){
        cout<<2<<" ";
        return;
    }

    printEven(n-2);
    cout<<n<<" ";
 }

int main(){
    // print the number from 1 to even n 
    int n=11;
    // if there will be any odd number then we can give this condition
    if(n%2==1)
    n--;
    // printEven(1 , n);
    printEven(n); // one argument only.. passing and reverse way doing and printing after the condtion matches
}