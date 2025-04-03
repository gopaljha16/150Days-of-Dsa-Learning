#include <iostream>
using namespace std;

int ReverseArray(int arr[] , int index , int n){
    // base case
    if(index==n)
    return 0;

    ReverseArray(arr, index+1 , n);
    cout<<arr[index]<<" ";
}

int main(){
    int arr[] = {3,7,6,2,8};
    ReverseArray(arr , 0 , 5);
}