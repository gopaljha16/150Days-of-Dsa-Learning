#include <iostream>
using namespace std;


int MaxElem(int arr[] , int index , int n){
 
    //base case
    if(index==n-1)
    return arr[index];

    return max(arr[index] , MaxElem(arr , index+1 , n));
}

// 1: Find the Maximum element in a given array of size N.

int main(){
   int arr[] = {7,2,5,22,1};
   cout<<MaxElem(arr , 0 , 5);
}