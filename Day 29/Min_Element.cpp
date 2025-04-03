#include <iostream>
using namespace std;

int MinEle(int arr[] , int index , int n){

    // base case
    if( index==n-1)
    return arr[index];
       
    return min(arr[index] , MinEle(arr , index+1 , n));
}

int main(){
   int arr[] = {7,2,4,1,6};
   cout<<MinEle(arr , 0 , 5);
}