#include <iostream>
using namespace std;

bool LinearSearch(int arr[] , int x , int index , int n){
    // base case
    if(index==n)
    return 0;


    // matching
    if(arr[index]==x)
    return 1;

    return LinearSearch(arr, x , index+1 , n );
}

int main(){
    int arr[] = {2,4,7,3,11,8,12};
    int x= 0;
    int n= 7;
    cout<<LinearSearch(arr ,x , 0 , n );
}