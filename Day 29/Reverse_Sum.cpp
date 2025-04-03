#include <iostream>
using namespace std;

int ReverseSum(int arr[] , int index ){

    if(index==0)
    return arr[index];

    cout<<arr[index]<<" ";
    return ReverseSum(arr , index-1 );
}

int main(){

    int arr[] = {3,4,5,8,2};
    cout<<ReverseSum(arr, 4);
}