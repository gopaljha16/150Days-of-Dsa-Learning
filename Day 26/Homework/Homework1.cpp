#include <iostream>
using namespace std;

// 1: Print all odd numbers from 1 to n using recursion

//  void printOdd(int n){

//     if(n==15){
//         return;
//     }
     
//     cout<<n<<" ";
//     printOdd(n+2);
//  }


// reverse method 
void printOdd(int n){

    if(n==1){
        cout<<1<<" ";
        return;
    }
   
    printOdd(n-2);
    cout<<n<<" ";
}

int main(){
    
     int n; 
     cout<<"Enter yout n value :- ";
     cin>>n;

    //  if user puts even number then this condition will we fix that
    if(n%2==0)
    n++;

    printOdd(n);
     
    return 0;
}