#include <iostream>
using namespace std;
// it will return the value so integer
 int fact(int n){
     //base condition
     if(n==1 || n==0){ // one more condition that if n==0 then it should be 1 or else it will give error and it will run infinite time and we will get integer overflow..
        return 1;
     }
     
    return n * fact(n-1);
 }

int main(){
   int n;
   cout<<"Enter your factorial Number :- ";
   cin>>n;

//    if user gives negative number
 if(n<0){
    cout<<"Factorial of negative number is not possible";
    return 0;
 }

   cout<<fact(n)<<endl;

   return 0;
}