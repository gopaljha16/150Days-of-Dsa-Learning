#include <iostream>
using namespace std;
   
int Pow(int num , int n){

    //  base condition
    if(n==0)
    return 1;
    
    if(n==1)
    return num;

    return num * Pow(num , n-1);
}

int main(){
    int power;
    cout<<"Enter what you want to put in your power :- ";
    cin>>power;

    int num ; 
    cout<<"Enter the number :- ";
    cin>>num;

    cout<<Pow(num ,  power);
}