#include <iostream>
using namespace std;

int PfSum(int arr[] , int index , int n , int sum){
    //base case
    if(index==n)
    return sum==0;

    //left + right  adding here
    return PfSum(arr , index+1 , n , sum) + PfSum(arr , index+1 , n , sum-arr[index]);
}

int main(){
    int arr[] = {2,5,6,1};
    int sum = 9;
   cout<<PfSum(arr , 0 , 4 , sum);
}