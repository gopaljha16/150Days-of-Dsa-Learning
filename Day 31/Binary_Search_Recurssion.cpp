#include <iostream>
using namespace std;

bool Binarysearch(int arr[] , int start , int end , int x){
    
    // base case
    if(start>end)
    return 0;

    // mid 
    int mid = start + (end - start)/2;
    if(arr[mid]==x)
    return 1;
    else if(arr[mid]>x)
    return Binarysearch(arr, start , mid-1, x);
    else
    return Binarysearch(arr , mid+1 , end , x);

}

int main(){

    int arr[] = {3,8,11,15,20,22}; // an non - decreasing array
    cout<<Binarysearch(arr,0 , 5 , 30);
    
}