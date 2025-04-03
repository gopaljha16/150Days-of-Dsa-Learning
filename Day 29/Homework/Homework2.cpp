#include <iostream>
using namespace std;

int Product(int arr[] , int index , int n){
    

    // base condition
    if(index==n-1)
    return arr[index];

    return arr[index]*Product(arr , index+1 , n);
}

int main(){

// 2: Find the Product of all elements in a given array of size N.
  int arr[] = {1,2,3,4,5};
  cout<<Product(arr , 0 , 5);
}