#include <iostream>
using namespace std;

int PrintArray(int arr[] , int index , int n){

    //base case..
    if(index==n)
    return 0;

    cout<<arr[index]<<" ";
    return PrintArray(arr , index+1 , n);
}

int main(){
    int arr[] = {3,7,6,2,8};
    PrintArray(arr , 0 , 5);
}