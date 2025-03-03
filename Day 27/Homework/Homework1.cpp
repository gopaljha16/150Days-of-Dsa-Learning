#include <iostream>
using namespace std;

 int cube(int n){
       
    if(n==1)
    return 1;
    
    return n*n*n + cube(n-1);

 }

int main(){

    // 1: Sum of cubes of N natural numbers using Recursion.

    int n;
    cout<<"Enter the n value :- ";
    cin>>n;

    cout<<cube(n);
}