#include <iostream>
using namespace std;

 int SumRepetition(int arr[] , int index , int n , int sum){
    // base case
    if(sum==0)
    return 1;

    if(index==n || sum<0)
    return 0;

    // here the repetiontion should be one side taking and another sidde not moving taking that index only until it make sum 0;
    return SumRepetition(arr , index+1 , n , sum) + SumRepetition(arr  , index , n , sum-arr[index]);
 }

int main(){

    int arr[] = {2,3,4 ,8};
    int sum = 8;
    cout<<SumRepetition(arr , 0 , 3 , sum); 
}