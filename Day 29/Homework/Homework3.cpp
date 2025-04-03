#include <iostream>
using namespace std;

void EvenElem(int arr[] , int index , int n ){
    
    // base condition
    if(index==n-1)
    return;

    if(arr[index]%2==0)
    cout<<arr[index]<<" ";

   return EvenElem(arr , index+1, n); 
}

int main(){

    // Find the Number of even elements in a given array of size N.
    int arr[] = {1,2,3,4,5};
    EvenElem(arr ,0 , 5);
}