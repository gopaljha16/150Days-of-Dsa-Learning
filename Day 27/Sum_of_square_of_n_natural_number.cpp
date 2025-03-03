#include <iostream>
using namespace std;


 int Sq(int n){

     //base case
     if(n==1)
     return 1;

    return n*n + Sq(n-1);
 }

int main(){
    // sum of square of n natural number 
    int n;
    cout<<"Enter you number :- ";
    cin>>n;
    if(n<1)
    return 0;

    cout<<Sq(n);
}